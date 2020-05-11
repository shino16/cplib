#pragma once

#include "geometry/Pt.cpp"
#include "template.cpp"

namespace FFT {
using dbl = double;

using complex = Pt<dbl>;

inline complex conj(complex a) { return complex(a.x, -a.y); }

int base = 1;
vector<complex> root = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const dbl PI = asinl(1) * 2;

void prepare(int nbase) {
  if (nbase <= base) return;

  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

  root.resize(1 << nbase);

  rep(b, base, nbase) {
    dbl theta = 2 * PI / (1 << (b + 1));
    for (int i = 1 << (b - 1); i < (1 << b); i++) {
      root[i << 1] = root[i];
      dbl aug = theta * (2 * i + 1 - (1 << b));
      root[(i << 1) + 1] = complex(cos(aug), sin(aug));
    }
  }
}

template <typename T, typename U>
vector<T> cast(const vector<U>& v) {
  vector<T> res(v.size());
  if (is_integral<T>::value)
    rep(i, v.size()) res[i] = T(round(v[i]));
  else
    copy(all(v), res.begin());
  return res;
}

void fft(vector<complex>& A) {
  int n = A.size();
  assert((n & (n - 1)) == 0);

  int zeros = __builtin_ctz(n);
  prepare(zeros + 1);
  int shift = base - zeros;
  rep(i, n) if (i < (rev[i] >> shift)) swap(A[i], A[rev[i] >> shift]);

  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        complex z = A[i + j + k] * root[j + k];
        A[i + j + k] = A[i + j] - z;
        A[i + j] += z;
      }
    }
  }
}

template <typename T>
vector<T> multiply(const vector<T>& A, const vector<T>& B) {
  int need = A.size() + B.size() - 1;
  int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));

  vector<complex> fa(sz);
  rep(i, A.size()) fa[i].x = dbl(A[i]);
  rep(i, B.size()) fa[i].y = dbl(B[i]);
  fft(fa);

  complex r(0, -0.25 / sz);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    if (i != j) fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    fa[i] = z;
  }
  fft(fa);

  vector<T> res(need);
  rep(i, need) res[i] = fa[i].x;

  return res;
}

template <typename T>
vector<dbl> div(vector<T>& A, vector<T>& B) {
  static vector<dbl> q_rev;
  static vector<vector<dbl>> t;  // t[i] * B == 0 mod x^2^i

  while (B.back() == 0) B.pop_back();
  if (not equal(all(B), rall(q_rev))) {
    q_rev.resize(B.size());
    copy(rall(B), q_rev.begin());
    t.clear();
    t.emplace_back(vector<dbl>{1 / q_rev[0]});
  }

  int n = A.size(), m = B.size();
  int k = 32 - __builtin_clz(n - m);  // ceil(log2(n-m+1))
  rep((1 << k) - n) A.emplace_back(dbl(0));
  n = A.size();

  rep(k + 1 - t.size()) {
    vector<dbl> next = multiply(multiply(t.back(), t.back()), q_rev);
    next.resize(1 << t.size());
    for (auto& a : next) a *= -1;
    rep(i, t.back().size()) next[i] += t.back()[i] * 2;
    t.emplace_back(move(next));
  }

  reverse(all(A));
  vector<dbl> res = multiply(t[k], vector<dbl>(all(A)));
  res.resize(n - m + 1);
  reverse(all(A));
  reverse(all(res));

  return res;
}

template <typename Vector>
vector<dbl> div(Vector&& A, Vector&& B) {
  return div(A, B);
}

template <typename T>
pair<vector<dbl>, vector<dbl>> divmod(vector<T>& A, vector<T>& B,
                                      dbl eps = 1e-9) {
  vector<dbl> q = div(A, B);
  vector<dbl> r = multiply(q, cast<dbl>(B));
  r.resize(A.size());
  rep(i, r.size()) r[i] = A[i] - r[i];
  while (r.size() > 1 and abs(r.back()) < eps) r.pop_back();
  return make_pair(q, r);
}

template <typename Vector>
pair<vector<dbl>, vector<dbl>> divmod(Vector&& A, Vector&& B, dbl eps = 1e-9) {
  return divmod(A, B, eps);
}

template <typename Vector>
vector<dbl> mod(Vector&& A, Vector&& B, dbl eps = 1e-9) {
  return divmod(A, B, eps).second;
}

};  // namespace FFT
