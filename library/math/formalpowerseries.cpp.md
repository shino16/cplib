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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/formalpowerseries.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/formalpowerseries.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 23:02:46+09:00




## Depends on

* :x: <a href="../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/formalpowerseries.cpp"

#line 2 "template.cpp"

#ifndef LOCAL
#pragma GCC diagnostic warning "-w"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl '\n'
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod) if (t & 1) (res *= e) %= mod; return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r); if (r < 0) return 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return res;
}
template <typename T> T divceil(T m, T d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// debug stuff
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *itr;
itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, set<T>& set_var) { os << "{"; repi(itr,
set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}"; return
os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const pair<T, U
>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func() {
debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail &&...
tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(std::move(
tail)...); }
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#pragma GCC diagnostic pop


// loops rep(until) / rep(var, until) / rep(var, from, until) / repr (reversed order)
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define rep(...) OVERLOAD3(__VA_ARGS__, REPEAT_FROM_UNTIL, REPEAT_UNTIL, REPEAT)(__VA_ARGS__)
#define REPEAT(times) REPEAT_CNT(_repeat, __COUNTER__, times)
#define REPEAT_CNT(_repeat, cnt, times) REPEAT_CNT_CAT(_repeat, cnt, times)
#define REPEAT_CNT_CAT(_repeat, cnt, times) REPEAT_FROM_UNTIL(_repeat ## cnt, 0, times)
#define REPEAT_UNTIL(name, times) REPEAT_FROM_UNTIL(name, 0, times)
#define REPEAT_FROM_UNTIL(name, from, until) for (int name = from, name ## __until = (until); name < name ## __until; name++)
#define repr(...) OVERLOAD3(__VA_ARGS__, REPR_FROM_UNTIL, REPR_UNTIL, REPEAT)(__VA_ARGS__)
#define REPR_UNTIL(name, times) REPR_FROM_UNTIL(name, 0, times)
#define REPR_FROM_UNTIL(name, from, until) for (int name = (until)-1, name ## __from = (from); name >= name ## __from; name--)



#line 4 "math/formalpowerseries.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

