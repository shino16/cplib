#pragma once

#include "template.cpp"

// credit to @beet-aizu
template <typename M, typename Conv>
struct FormalPowerSeries {
  using Poly = vector<M>;
  const Conv conv;
  FormalPowerSeries(const Conv& _conv) : conv(_conv) {}

  Poly pre(const Poly& as, int deg) {
    return Poly(as.begin(), as.begin() + min((int)as.size(), deg));
  }

  Poly add(const Poly& as, const Poly& bs) {
    int sz = max(as.size(), bs.size());
    Poly cs(sz, M(0));
    for (int i = 0; i < (int)as.size(); i++) cs[i] += as[i];
    for (int i = 0; i < (int)bs.size(); i++) cs[i] += bs[i];
    return cs;
  }

  Poly sub(const Poly& as, const Poly& bs) {
    int sz = max(as.size(), bs.size());
    Poly cs(sz, M(0));
    for (int i = 0; i < (int)as.size(); i++) cs[i] += as[i];
    for (int i = 0; i < (int)bs.size(); i++) cs[i] -= bs[i];
    return cs;
  }

  Poly mul(Poly as, Poly bs) { return conv(as, bs); }

  Poly mul(const Poly& as, M k) {
    Poly res = as;
    for (auto& a : res) a *= k;
    return res;
  }

  // F(0) must not be 0
  Poly inv(const Poly& as, int deg) {
    assert(as[0] != M(0));
    Poly rs({M(1) / as[0]});
    for (int i = 1; i < deg; i <<= 1)
      rs = pre(sub(add(rs, rs), mul(mul(rs, rs), pre(as, i << 1))), i << 1);
    return rs;
  }

  // not zero
  Poly div(const Poly& as, const Poly& bs) {
    while (as.back() == M(0)) as.pop_back();
    while (bs.back() == M(0)) bs.pop_back();
    if (bs.size() > as.size()) return Poly();
    int need = as.size() - bs.size() + 1;
    Poly ds = pre(mul(Poly(rall(as)), inv(Poly(rall(bs)), need)), need);
    return rall(ds);
  }

  Poly mod(const Poly& as, const Poly& bs) {
    if (as == Poly(as.size(), 0)) return Poly({0});
    Poly res = sub(as, mul(div(as, bs), bs));
    while (not res.empty() and res.back() == M(0)) res.pop_back();
    return res;
  }

  // F(0) must be 1
  Poly sqrt(const Poly& as, int deg) {
    assert(as[0] == M(1));
    M inv2 = M(1) / M(2);
    Poly ss({M(1)});
    for (int i = 1; i < deg; i <<= 1) {
      ss = pre(add(ss, mul(pre(as, i << 1), inv(ss, i << 1))), i << 1);
      for (M& x : ss) x *= inv2;
    }
    return ss;
  }

  Poly derivative(const Poly& as) {
    int n = as.size();
    Poly rs(n - 1);
    for (int i = 1; i < n; i++) rs[i - 1] = as[i] * M(i);
    return rs;
  }

  Poly integral(const Poly& as) {
    static binomial<M> binom(0);
    int n = as.size();
    if (binom.invfact.size() <= n)
      binom = binomial<M>(1 << (32 - __builtin_clz(n) + 1));
    Poly rs(n + 1);
    rs[0] = M(0);
    for (int i = 0; i < n; i++) rs[i + 1] = as[i] * binom.invfact[i + 1] * binom.fact[i];
    return rs;
  }

  // F(0) must be 1
  Poly log(const Poly& as, int deg) {
    return pre(integral(mul(derivative(as), inv(as, deg))), deg);
  }

  // F(0) must be 0
  Poly exp(Poly as, int deg) {
    Poly f({M(1)});
    as[0] += M(1);
    for (int i = 1; i < deg; i <<= 1)
      f = pre(mul(f, sub(pre(as, i << 1), log(f, i << 1))), i << 1);
    return f;
  }
};
