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


# :warning: tree/rerooting.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-26 19:55:50+09:00




## Depends on

* :heavy_check_mark: <a href="../graph/graph.cpp.html">graph/graph.cpp</a>
* :question: <a href="../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "graph/graph.cpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Edge, typename Apply, typename Merge>
class ReRooting {
public:
  struct Node {
    int to, rev;
    Edge data;
    Node(int to, Edge data) : to(to), data(data) {}
    bool operator<(const Node &v) const { return to < v.to; };
  };

private:
  vector<vector<Node>> G;
  vector<vector<T>> ld, rd;
  vector<int> lp, rp;

  const T id;
  const Apply apply;
  const Merge merge;

public:
  ReRooting(int n, T id, const Apply &apply = Apply(),
            const Merge &merge = Merge())
      : G(n), ld(n), rd(n), lp(n), rp(n), id(id), apply(apply), merge(merge) {}

  // d: propagate v to u
  void add_edge(int u, int v, Edge d, Edge e) {
    G[u].emplace_back(v, d);
    G[v].emplace_back(u, e);
  }

  void add_edge(int u, int v, Edge d) { add_edge(u, v, d, d); }

private:
  // k: idx for edge (not vertex)
  T dfs(int v, int k) {
    while (lp[v] != k and lp[v] < (int)G[v].size()) {
      const auto &e = G[v][lp[v]];
      ld[v][lp[v] + 1] = merge(ld[v][lp[v]], apply(dfs(e.to, e.rev), e.data));
      lp[v]++;
    }
    if (k < 0) return ld[v].back();
    while (rp[v] != k and rp[v] >= 0) {
      const auto &e = G[v][rp[v]];
      rd[v][rp[v]] = merge(rd[v][rp[v] + 1], apply(dfs(e.to, e.rev), e.data));
      rp[v]--;
    }
    return merge(ld[v][k], rd[v][k + 1]);
  }

  int search(vector<Node> &vs, int idx) {
    return lower_bound(all(vs), Node(idx, vs[0].data)) - vs.begin();
  }

public:
  vector<T> build() {
    int n = G.size();
    for (int i = 0; i < n; i++) {
      sort(all(G[i]));
      ld[i].assign((int)G[i].size() + 1, id);
      rd[i].assign((int)G[i].size() + 1, id);
      lp[i] = 0;
      rp[i] = (int)G[i].size() - 1;
    }

    for (int i = 0; i < n; i++)
      for (Node &t : G[i]) t.rev = search(G[t.to], i);

    vector<T> res;
    for (int i = 0; i < n; i++) res.emplace_back(dfs(i, -1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v, int p) {
    int k = search(G[p], v);
    assert(k < (int)G[p].size() and G[p][k].to == v);
    return apply(dfs(v, G[p][k].rev), G[p][k].data);
  }
};
#pragma GCC diagnostic pop

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/rerooting.cpp"

#line 2 "template.cpp"

#ifndef LOCAL
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
template <typename T, typename U> T divceil(T m, U d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// debugging stuff
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, const map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *
itr; itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, const set<T>& set_var) { os << "{"; repi(
itr, set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}";
return os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const
pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func(
) { debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail
&&... tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(forward
<Tail>(tail)...); }
#ifdef LOCAL
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#else
#define dump(...) ({})
#endif
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
#line 5 "tree/rerooting.cpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Edge, typename Apply, typename Merge>
class ReRooting {
public:
  struct Node {
    int to, rev;
    Edge data;
    Node(int to, Edge data) : to(to), data(data) {}
    bool operator<(const Node &v) const { return to < v.to; };
  };

private:
  vector<vector<Node>> G;
  vector<vector<T>> ld, rd;
  vector<int> lp, rp;

  const T id;
  const Apply apply;
  const Merge merge;

public:
  ReRooting(int n, T id, const Apply &apply = Apply(),
            const Merge &merge = Merge())
      : G(n), ld(n), rd(n), lp(n), rp(n), id(id), apply(apply), merge(merge) {}

  // d: propagate v to u
  void add_edge(int u, int v, Edge d, Edge e) {
    G[u].emplace_back(v, d);
    G[v].emplace_back(u, e);
  }

  void add_edge(int u, int v, Edge d) { add_edge(u, v, d, d); }

private:
  // k: idx for edge (not vertex)
  T dfs(int v, int k) {
    while (lp[v] != k and lp[v] < (int)G[v].size()) {
      const auto &e = G[v][lp[v]];
      ld[v][lp[v] + 1] = merge(ld[v][lp[v]], apply(dfs(e.to, e.rev), e.data));
      lp[v]++;
    }
    if (k < 0) return ld[v].back();
    while (rp[v] != k and rp[v] >= 0) {
      const auto &e = G[v][rp[v]];
      rd[v][rp[v]] = merge(rd[v][rp[v] + 1], apply(dfs(e.to, e.rev), e.data));
      rp[v]--;
    }
    return merge(ld[v][k], rd[v][k + 1]);
  }

  int search(vector<Node> &vs, int idx) {
    return lower_bound(all(vs), Node(idx, vs[0].data)) - vs.begin();
  }

public:
  vector<T> build() {
    int n = G.size();
    for (int i = 0; i < n; i++) {
      sort(all(G[i]));
      ld[i].assign((int)G[i].size() + 1, id);
      rd[i].assign((int)G[i].size() + 1, id);
      lp[i] = 0;
      rp[i] = (int)G[i].size() - 1;
    }

    for (int i = 0; i < n; i++)
      for (Node &t : G[i]) t.rev = search(G[t.to], i);

    vector<T> res;
    for (int i = 0; i < n; i++) res.emplace_back(dfs(i, -1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v, int p) {
    int k = search(G[p], v);
    assert(k < (int)G[p].size() and G[p][k].to == v);
    return apply(dfs(v, G[p][k].rev), G[p][k].data);
  }
};
#pragma GCC diagnostic pop

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

