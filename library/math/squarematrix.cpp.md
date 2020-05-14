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


# :warning: math/squarematrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/squarematrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 23:02:46+09:00




## Depends on

* :x: <a href="../template.cpp.html">template.cpp</a>
* :warning: <a href="../util/doubling.cpp.html">util/doubling.cpp</a>
* :warning: <a href="../util/mapping.cpp.html">util/mapping.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "util/doubling.cpp"

template <typename M = ll>
class SquareMatrix {
 public:
  using arr = vector<M>;
  using mat = vector<arr>;
  int n;

 private:
  mat data;

  SquareMatrix(int n_) : n(n_), data(n, arr(n)) {}
  SquareMatrix(const mat& dat_) : n(dat_.size()), data(dat_) {}

  bool operator==(const SquareMatrix& rhs) const { return data == rhs.data; }
  bool operator!=(const SquareMatrix& rhs) const { return data != rhs.data; }

  size_t size() const { return n; }
  arr& operator[](size_t k) { return data[k]; }
  const arr& operator[](size_t k) const { return data[k]; }

  static SquareMatrix mul_unit(int n) {
    SquareMatrix res(n);
    rep(i, n) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    rep(i, n) rep(j, n) rep(k, n) res[i][j] += (data[i][k] * rhs[k][j]);
    return res;
  }

  arr operator*(const arr& rhs) const {
    arr res(n);
    rep(i, n) rep(j, n) res[i] += data[i][j] * rhs[j];
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++) res[i][j] = data[i][j] + rhs[i][j];
    return res;
  }

  SquareMatrix pow(ll exp) const {
    using Doubling = Doubling<SquareMatrix, multiplies<SquareMatrix>>;
    return Doubling::pow(*this, exp, mul_unit(n));
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, n) rep(j, i + 1, n) swap(res.data[i][j], res.data[j][i]);
    return res;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/squarematrix.cpp"

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



#line 2 "util/doubling.cpp"

#line 2 "util/mapping.cpp"

#line 4 "util/mapping.cpp"

class Mapping {
 public:
  struct Combine {
    Mapping operator()(const Mapping& lhs, const Mapping& rhs) {
      if (lhs.f.empty()) return rhs;
      if (rhs.f.empty()) return lhs;
      assert(lhs.f.size() == rhs.f.size());
      int n = lhs.f.size();
      vector<int> f(n);
      rep(x, n) {
        int y = rhs.f[x];
        f[x] = 0 <= y and y < n ? lhs.f[y] : y;
      }
      return Mapping(move(f));
    }
  };

 private:
  vector<int> f;

 public:
  Mapping() = default;
  Mapping(int n) : f(n) { iota(all(f), 0); }
  Mapping(const vector<int>& f_) : f(f_) {}
  Mapping(vector<int>&& f_) : f(move(f_)) {}

  int operator()(int x) { return f[x]; }
};
#line 5 "util/doubling.cpp"

template <typename T = Mapping, typename Combine = typename T::Combine>
class Doubling {
 private:
  vector<T> data;
  const T unit;
  const Combine combine;

 public:
  Doubling(T unit_ = {}, Combine combine_ = {})
      : data({unit_}), unit(unit_), combine(combine_) {}

 private:
  void prepare(ll n) {
    if (n <= 1) return;
    int need = 64 - __builtin_clz(n-1);
    rep(need - data.size()) data.push_back(combine(data.back(), data.back()));
  }

 public:
  T pow(ll exp) {
    prepare(exp);
    T res = unit;
    int i = 0;
    for (; exp; exp >>= 1, i++)
      if (exp & 1) res = combine(res, data[i]);
    return res;
  }

  static T pow(T base, ll exp, T unit = {}, Combine combine = {}) {
    T res = unit;
    for (; exp; exp >>= 1, base = combine(base, base))
      if (exp & 1) res = combine(res, base);
    return res;
  }
};
#line 5 "math/squarematrix.cpp"

template <typename M = ll>
class SquareMatrix {
 public:
  using arr = vector<M>;
  using mat = vector<arr>;
  int n;

 private:
  mat data;

  SquareMatrix(int n_) : n(n_), data(n, arr(n)) {}
  SquareMatrix(const mat& dat_) : n(dat_.size()), data(dat_) {}

  bool operator==(const SquareMatrix& rhs) const { return data == rhs.data; }
  bool operator!=(const SquareMatrix& rhs) const { return data != rhs.data; }

  size_t size() const { return n; }
  arr& operator[](size_t k) { return data[k]; }
  const arr& operator[](size_t k) const { return data[k]; }

  static SquareMatrix mul_unit(int n) {
    SquareMatrix res(n);
    rep(i, n) res[i][i] = M(1);
    return res;
  }

  SquareMatrix operator*(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    rep(i, n) rep(j, n) rep(k, n) res[i][j] += (data[i][k] * rhs[k][j]);
    return res;
  }

  arr operator*(const arr& rhs) const {
    arr res(n);
    rep(i, n) rep(j, n) res[i] += data[i][j] * rhs[j];
    return res;
  }

  SquareMatrix operator+(const SquareMatrix& rhs) const {
    SquareMatrix res(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++) res[i][j] = data[i][j] + rhs[i][j];
    return res;
  }

  SquareMatrix pow(ll exp) const {
    using Doubling = Doubling<SquareMatrix, multiplies<SquareMatrix>>;
    return Doubling::pow(*this, exp, mul_unit(n));
  }

  SquareMatrix transpose() const {
    SquareMatrix res = *this;
    rep(i, n) rep(j, i + 1, n) swap(res.data[i][j], res.data[j][i]);
    return res;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

