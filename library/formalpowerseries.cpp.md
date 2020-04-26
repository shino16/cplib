---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: formalpowerseries.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/formalpowerseries.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename M>
class binomial {
public:
  vector<M> fact, invfact;
  binomial(int n) : fact(n+1), invfact(n+1) {
    fact[0] = 1;
    rep(i, n) fact[i+1] = fact[i] * M(i+1);
    invfact[n] = M(1) / fact[n];
    repr(i, n) invfact[i] = invfact[i+1] * M(i+1);
  }
  M operator()(int n, int r) {
    chmin(r, n-r);
    if (r < 0) return M(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};

// originally written by @beet-aizu
template <typename M_>
struct FormalPowerSeries {
  using M = M_;

  using Poly = vector<M>;
  using Conv = function<Poly(Poly, Poly)>;
  const Conv conv;
  FormalPowerSeries(Conv _conv) : conv(_conv) {}

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "formalpowerseries.cpp"

template <typename M>
class binomial {
public:
  vector<M> fact, invfact;
  binomial(int n) : fact(n+1), invfact(n+1) {
    fact[0] = 1;
    rep(i, n) fact[i+1] = fact[i] * M(i+1);
    invfact[n] = M(1) / fact[n];
    repr(i, n) invfact[i] = invfact[i+1] * M(i+1);
  }
  M operator()(int n, int r) {
    chmin(r, n-r);
    if (r < 0) return M(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};

// originally written by @beet-aizu
template <typename M_>
struct FormalPowerSeries {
  using M = M_;

  using Poly = vector<M>;
  using Conv = function<Poly(Poly, Poly)>;
  const Conv conv;
  FormalPowerSeries(Conv _conv) : conv(_conv) {}

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

```
{% endraw %}

<a href="../index.html">Back to top page</a>

