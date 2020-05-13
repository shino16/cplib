#pragma once

#include "template.cpp"
#include "math/modint.cpp"

constexpr ll mods(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}

constexpr int primitive_roots(int x) {
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template <int X = 2>
class NTT {
 public:
  static constexpr int md = mods(X);
  static constexpr int rt = primitive_roots(X);
  using mint = modint<md>;

 private:
  vector<vector<mint>> root, rroot;

  void prepare(int n) {
    if (root.size() >= n) return;
    root.resize(n);
    rroot.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!root[i].empty()) continue;
      mint w = pow(mint(rt), (md - 1) / (i << 1));
      mint rw = mint(1) / w;
      root[i].resize(i);
      rroot[i].resize(i);
      root[i][0] = mint(1);
      rroot[i][0] = mint(1);
      rep(k, 1, i) root[i][k] = root[i][k - 1] * w,
                   rroot[i][k] = rroot[i][k - 1] * rw;
    }
  }

 public:
  void ntt(vector<mint>& A, bool reverse) {
    int n = A.size();
    assert((n & (n - 1)) == 0);
    prepare(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1) {}
      if (i > j) swap(A[i], A[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          mint z = A[i + j + k] * (reverse ? rroot[i][k] : root[i][k]);
          A[i + j + k] = A[j + k] - z;
          A[j + k] += z;
        }
      }
    }

    if (reverse) {
      mint tmp = mint(1) / mint(n);
      rep(i, n) A[i] *= tmp;
    }
  }

  vector<mint> multiply(vector<mint> A, vector<mint> B) {
    int need = A.size() + B.size() - 1;
    int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));

    A.resize(sz, mint(0));
    B.resize(sz, mint(0));

    ntt(A, 0);
    ntt(B, 0);
    rep(i, sz) A[i] *= B[i];
    ntt(A, 1);

    A.resize(need);
    return A;
  }

  vector<ll> multiply(vector<ll> A, vector<ll> B) {
    vector<mint> am(A.size()), bm(B.size());
    rep(i, am.size()) am[i] = mint(A[i]);
    rep(i, bm.size()) bm[i] = mint(B[i]);
    vector<mint> cm = multiply(am, bm);
    vector<ll> cs(cm.size());
    rep(i, cs.size()) cs[i] = cm[i].value;
    return cs;
  }
};
