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


# :heavy_check_mark: graph/strongly-connected-components.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly-connected-components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 23:32:59+09:00




## Depends on

* :heavy_check_mark: <a href="graph.cpp.html">graph/graph.cpp</a>
* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>
* :heavy_check_mark: <a href="../util/fix.cpp.html">util/fix.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/0366.test.cpp.html">verify/aoj/0366.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "graph/graph.cpp"
#include "util/fix.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/strongly-connected-components.cpp"

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


#line 2 "graph/graph.cpp"

#line 4 "graph/graph.cpp"

struct Edge {
  int to; ll cost;
  Edge(int _to) : to(_to), cost(1) {}
  Edge(int _to, ll _cost) : to(_to), cost(_cost) {}
  operator int() const { return to; }
};

using Graph = vector<vector<Edge>>;
#line 2 "util/fix.cpp"

#line 4 "util/fix.cpp"

template <typename F>
class FixPoint : private F {
 public:
  explicit constexpr FixPoint(F&& f) : F(forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F> decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}
#line 6 "graph/strongly-connected-components.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

