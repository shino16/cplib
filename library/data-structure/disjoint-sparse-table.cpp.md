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


# :heavy_check_mark: data-structure/disjoint-sparse-table.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/disjoint-sparse-table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-15 01:20:06+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>
* :heavy_check_mark: <a href="../util/function-objects.cpp.html">util/function-objects.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/yuki/1036.test.cpp.html">verify/yuki/1036.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "util/function-objects.cpp"

template <typename T, typename F>
class DisjointSparseTable {
 private:
  const int n, h;
  vector<vector<T>> table;
  const T unit;
  const F f;

 public:
  DisjointSparseTable() {}

  template <typename Iter,
            enable_if_t<is_same<typename Iter::value_type, T>::value>* = nullptr>
  DisjointSparseTable(Iter first, Iter last, T unit_, F f_ = F())
      : n(distance(first, last)),
        h(32 - __builtin_clz(n)),
        table(h, vector<T>(n)),
        unit(unit_),
        f(f_) {
    move(first, last, table[0].begin());
    build();
  }

  template <typename Iter,
            enable_if_t<!is_same<typename Iter::value_type, T>::value>* = nullptr>
  [[deprecated]] DisjointSparseTable(Iter first, Iter last, T unit_, F f_ = F())
      : n(distance(first, last)),
        h(32 - __builtin_clz(n)),
        table(h, vector<T>(n)),
        unit(unit_),
        f(f_) {
    move(first, last, table[0].begin());
    build();
  }

 private:
  void build() {
    rep(s, 1, h) rep(k, (n + (1 << (s + 1)) - 1) >> (s + 1)) {
      int l = k << (s + 1);
      int m = min(n, l + (1 << s));
      int r = min(n, m + (1 << s));
      table[s][m - 1] = table[0][m - 1];
      repr(i, l, m - 1) table[s][i] = f(table[0][i], table[s][i + 1]);
      if (m != n) {
        table[s][m] = table[0][m];
        rep(i, m + 1, r) table[s][i] = f(table[s][i - 1], table[0][i]);
      }
    }
  }

 public:
  T fold(int l, int r) {
    r--;
    if (l > r) return unit;
    if (l == r) return table[0][l];
    int s = 32 - __builtin_clz(l ^ r) - 1;
    return f(table[s][l], table[s][r]);
  }
};

#ifdef __cpp_deduction_guides
template <typename Iter, typename F>
DisjointSparseTable(Iter first, Iter last, typename Iter::value::type unit_,
                    F f_ = F())
    ->DisjointSparseTable<typename Iter::value_type, F>;
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/disjoint-sparse-table.cpp"

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
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
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


#line 2 "util/function-objects.cpp"

#line 4 "util/function-objects.cpp"

struct minT {
  template <typename T>
  T operator()(T a, T b) const {
    return min(a, b);
  }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const {
    return max(a, b);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct assignT {
  template <typename T>
  T operator()(T a, T b, int k = 0) const { return b; }
};
#pragma GCC diagnostic pop

struct plusT {
  template <typename T>
  T operator()(T a, T b, int k) const { return a + b * k; }
};
#line 5 "data-structure/disjoint-sparse-table.cpp"

template <typename T, typename F>
class DisjointSparseTable {
 private:
  const int n, h;
  vector<vector<T>> table;
  const T unit;
  const F f;

 public:
  DisjointSparseTable() {}

  template <typename Iter,
            enable_if_t<is_same<typename Iter::value_type, T>::value>* = nullptr>
  DisjointSparseTable(Iter first, Iter last, T unit_, F f_ = F())
      : n(distance(first, last)),
        h(32 - __builtin_clz(n)),
        table(h, vector<T>(n)),
        unit(unit_),
        f(f_) {
    move(first, last, table[0].begin());
    build();
  }

  template <typename Iter,
            enable_if_t<!is_same<typename Iter::value_type, T>::value>* = nullptr>
  [[deprecated]] DisjointSparseTable(Iter first, Iter last, T unit_, F f_ = F())
      : n(distance(first, last)),
        h(32 - __builtin_clz(n)),
        table(h, vector<T>(n)),
        unit(unit_),
        f(f_) {
    move(first, last, table[0].begin());
    build();
  }

 private:
  void build() {
    rep(s, 1, h) rep(k, (n + (1 << (s + 1)) - 1) >> (s + 1)) {
      int l = k << (s + 1);
      int m = min(n, l + (1 << s));
      int r = min(n, m + (1 << s));
      table[s][m - 1] = table[0][m - 1];
      repr(i, l, m - 1) table[s][i] = f(table[0][i], table[s][i + 1]);
      if (m != n) {
        table[s][m] = table[0][m];
        rep(i, m + 1, r) table[s][i] = f(table[s][i - 1], table[0][i]);
      }
    }
  }

 public:
  T fold(int l, int r) {
    r--;
    if (l > r) return unit;
    if (l == r) return table[0][l];
    int s = 32 - __builtin_clz(l ^ r) - 1;
    return f(table[s][l], table[s][r]);
  }
};

#ifdef __cpp_deduction_guides
template <typename Iter, typename F>
DisjointSparseTable(Iter first, Iter last, typename Iter::value::type unit_,
                    F f_ = F())
    ->DisjointSparseTable<typename Iter::value_type, F>;
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

