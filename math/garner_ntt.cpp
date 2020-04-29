#pragma once

#include "util/modint.cpp"

constexpr ll bmds(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}
constexpr int brts(int x) { // primitive roots
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}
template <int X>
struct NTT {
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = modint<md>;
  vector<vector<M> > rts, rrts;

  void ensure_base(int n) {
    if ((int)rts.size() >= n) return;
    rts.resize(n);
    rrts.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!rts[i].empty()) continue;
      M w = pow(M(rt), (md - 1) / (i << 1));
      M rw = M(1) / w;
      rts[i].resize(i);
      rrts[i].resize(i);
      rts[i][0] = M(1);
      rrts[i][0] = M(1);
      for (int k = 1; k < i; k++) {
        rts[i][k] = rts[i][k - 1] * w;
        rrts[i][k] = rrts[i][k - 1] * rw;
      }
    }
  }

  void ntt(vector<M>& as, bool f) {
    int n = as.size();
    assert((n & (n - 1)) == 0);
    ensure_base(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (i > j) swap(as[i], as[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          M z = as[i + j + k] * (f ? rrts[i][k] : rts[i][k]);
          as[i + j + k] = as[j + k] - z;
          as[j + k] += z;
        }
      }
    }

    if (f) {
      M tmp = M(1) / M(n);
      for (int i = 0; i < n; i++) as[i] *= tmp;
    }
  }

  vector<M> multiply(vector<M> as, vector<M> bs) {
    int need = as.size() + bs.size() - 1;
    int sz = 1;
    while (sz < need) sz <<= 1;
    as.resize(sz, M(0));
    bs.resize(sz, M(0));

    ntt(as, 0);
    ntt(bs, 0);
    for (int i = 0; i < sz; i++) as[i] *= bs[i];
    ntt(as, 1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as, vector<int> bs) {
    vector<M> am(as.size()), bm(bs.size());
    for (int i = 0; i < (int)am.size(); i++) am[i] = M(as[i]);
    for (int i = 0; i < (int)bm.size(); i++) bm[i] = M(bs[i]);
    vector<M> cm = multiply(am, bm);
    vector<int> cs(cm.size());
    for (int i = 0; i < (int)cs.size(); i++) cs[i] = cm[i].value;
    return cs;
  }
};

struct Garner {
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a, int b, int md) {
    int res = 1;
    a = a % md;
    while (b) {
      if (b & 1) res = (ll)res * a % md;
      a = (ll)a * a % md;
      b >>= 1;
    }
    return res;
  }

  static constexpr int inv(int x, int md) { return pow(x, md - 2, md); }

  inline void garner(int &c0, int c1, int c2, int m01, int mod) {
    static constexpr int r01 = inv(ntt0.md, ntt1.md);
    static constexpr int r02 = inv(ntt0.md, ntt2.md);
    static constexpr int r12 = inv(ntt1.md, ntt2.md);

    c1 = (ll)(c1 - c0) * r01 % ntt1.md;
    if (c1 < 0) c1 += ntt1.md;

    c2 = (ll)(c2 - c0) * r02 % ntt2.md;
    c2 = (ll)(c2 - c1) * r12 % ntt2.md;
    if (c2 < 0) c2 += ntt2.md;

    c0 %= mod;
    c0 += (ll)c1 * ntt0.md % mod;
    if (c0 >= mod) c0 -= mod;
    c0 += (ll)c2 * m01 % mod;
    if (c0 >= mod) c0 -= mod;
  }

  inline void garner(vector<vector<int>> &cs, int mod) {
    int m01 = (ll)ntt0.md * ntt1.md % mod;
    int sz = cs[0].size();
    for (int i = 0; i < sz; i++) garner(cs[0][i], cs[1][i], cs[2][i], m01, mod);
  }

  vector<int> multiply(vector<int> as, vector<int> bs, int mod) {
    vector<vector<int>> cs(3);
    cs[0] = ntt0.multiply(as, bs);
    cs[1] = ntt1.multiply(as, bs);
    cs[2] = ntt2.multiply(as, bs);
    size_t sz = as.size() + bs.size() - 1;
    for (auto &v : cs) v.resize(sz);
    garner(cs, mod);
    return cs[0];
  }

  template <typename T>
  decltype(auto) multiply(vector<T> am, vector<T> bm) {
    vector<int> as(am.size()), bs(bm.size());
    for (int i = 0; i < (int)as.size(); i++) as[i] = am[i].v;
    for (int i = 0; i < (int)bs.size(); i++) bs[i] = bm[i].v;
    vector<int> cs = multiply(as, bs, T::mod);
    vector<T> cm(cs.size());
    for (int i = 0; i < (int)cm.size(); i++) cm[i] = T(cs[i]);
    return cm;
  }
} garner;
NTT<0> Garner::ntt0;
NTT<1> Garner::ntt1;
NTT<2> Garner::ntt2;
