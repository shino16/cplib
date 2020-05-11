#pragma once

#include "template.cpp"

template <typename T, typename Conv>
struct FormalPowerSeries {
  using Poly = vector<T>;
  const Conv conv;
  FormalPowerSeries(const Conv& _conv) : conv(_conv) {}

  Poly pre(const Poly& A, int deg) {
    return Poly(A.begin(), A.begin() + min((int)A.size(), deg));
  }

  Poly add(const Poly& A, const Poly& B) {
    int sz = max(A.size(), B.size());
    Poly cs(sz, T(0));
    rep(i, A.size()) cs[i] += A[i];
    rep(i, B.size()) cs[i] += B[i];
    return cs;
  }

  Poly sub(const Poly& A, const Poly& B) {
    int sz = max(A.size(), B.size());
    Poly cs(sz, T(0));
    rep(i, A.size()) cs[i] += A[i];
    rep(i, B.size()) cs[i] -= B[i];
    return cs;
  }

  Poly mul(Poly& A, Poly& B) { return conv(A, B); }

  Poly mul(const Poly& A, T k) {
    Poly res = A;
    for (auto& a : res) a *= k;
    return res;
  }

  // A[0] != 0
  Poly inv(const Poly& A, int deg) {
    assert(A[0] != T(0));
    Poly rs({T(1) / A[0]});
    for (int i = 1; i < deg; i <<= 1)
      rs = pre(sub(add(rs, rs), mul(mul(rs, rs), pre(A, i << 1))), i << 1);
    return rs;
  }

  // nonzero
  Poly div(const Poly& A, const Poly& B) {
    while (not A.empty() and A.back() == T(0)) A.pop_back();
    while (B.back() == T(0)) B.pop_back();
    if (B.size() > A.size()) return Poly();
    int need = A.size() - B.size() + 1;
    Poly ds = pre(mul(Poly(rall(A)), inv(Poly(rall(B)), need)), need);
    reverse(all(ds));
    return ds;
  }

  Poly mod(const Poly& A, const Poly& B) {
    if (A == Poly(A.size(), 0)) return Poly({0});
    Poly res = sub(A, mul(div(A, B), B));
    while (not res.empty() and res.back() == T(0)) res.pop_back();
    return res;
  }

  // A[0] == 1
  Poly sqrt(const Poly& A, int deg) {
    assert(A[0] == T(1));
    T inv2 = T(1) / T(2);
    Poly ss({T(1)});
    for (int i = 1; i < deg; i <<= 1) {
      ss = pre(add(ss, mul(pre(A, i << 1), inv(ss, i << 1))), i << 1);
      for (T& x : ss) x *= inv2;
    }
    return ss;
  }

  Poly derivative(const Poly& A) {
    int n = A.size();
    Poly rs(n - 1);
    for (int i = 1; i < n; i++) rs[i - 1] = A[i] * T(i);
    return rs;
  }

  Poly integral(const Poly& A) {
    static binomial<T> binom(0);
    int n = A.size();
    if (binom.invfact.size() <= n)
      binom = binomial<T>(1 << (32 - __builtin_clz(n) + 1));
    Poly rs(n + 1);
    rs[0] = T(0);
    for (int i = 0; i < n; i++) rs[i + 1] = A[i] * binom.invfact[i + 1] * binom.fact[i];
    return rs;
  }

  // A[0] == 1
  Poly log(const Poly& A, int deg) {
    assert(A[0] == 1)
    return pre(integral(mul(derivative(A), inv(A, deg))), deg);
  }

  // A[0] == 0
  Poly exp(Poly A, int deg) {
    assert(A[0] == 0);
    Poly f({T(1)});
    A[0] += T(1);
    for (int i = 1; i < deg; i <<= 1)
      f = pre(mul(f, sub(pre(A, i << 1), log(f, i << 1))), i << 1);
    return f;
  }
};
