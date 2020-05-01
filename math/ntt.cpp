#pragma once

#include "template.cpp"

// credit to @beet-aizu
constexpr ll bmds(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}
constexpr int brts(int x) {  // primitive roots
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}
template <int X>
class NTT {
 public:
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = modint<md>;

 private:
  vector<vector<M>> rts, rrts;

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

 public:
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
NTT<2> ntt;  // mod 998244353
