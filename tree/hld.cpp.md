---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: graph/graph.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/0367.test.cpp
    title: verify/aoj/0367.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/hld.cpp\"\n\n#line 2 \"template.cpp\"\n\n#ifndef LOCAL\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma\
    \ GCC target(\"avx\")\n#endif\n#include <algorithm>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cmath>\n#include <functional>\n#include <iostream>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    using namespace std;\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using VI = vector<int>;\nusing VVI = vector<vector<int>>;\nusing VLL = vector<ll>;\n\
    using VVLL = vector<vector<ll>>;\nusing VB = vector<bool>;\nusing PII = pair<int,\
    \ int>;\nusing PLL = pair<ll, ll>;\nconstexpr int INF = 1000000007;\nconstexpr\
    \ ll INF_LL = 1'000'000'000'000'000'007;\n#define all(x) begin(x), end(x)\n#define\
    \ rall(x) rbegin(x), rend(x)\n#define newl '\\n'\n\n// loops rep(until) / rep(var,\
    \ until) / rep(var, from, until) / repr (reversed order)\n#define OVERLOAD3(_1,\
    \ _2, _3, name, ...) name\n#define rep(...) OVERLOAD3(__VA_ARGS__, REPEAT_FROM_UNTIL,\
    \ REPEAT_UNTIL, REPEAT)(__VA_ARGS__)\n#define REPEAT(times) REPEAT_CNT(_repeat,\
    \ __COUNTER__, times)\n#define REPEAT_CNT(_repeat, cnt, times) REPEAT_CNT_CAT(_repeat,\
    \ cnt, times)\n#define REPEAT_CNT_CAT(_repeat, cnt, times) REPEAT_FROM_UNTIL(_repeat\
    \ ## cnt, 0, times)\n#define REPEAT_UNTIL(name, times) REPEAT_FROM_UNTIL(name,\
    \ 0, times)\n#define REPEAT_FROM_UNTIL(name, from, until) for (int name = from,\
    \ name ## __until = (until); name < name ## __until; name++)\n#define repr(...)\
    \ OVERLOAD3(__VA_ARGS__, REPR_FROM_UNTIL, REPR_UNTIL, REPEAT)(__VA_ARGS__)\n#define\
    \ REPR_UNTIL(name, times) REPR_FROM_UNTIL(name, 0, times)\n#define REPR_FROM_UNTIL(name,\
    \ from, until) for (int name = (until)-1, name ## __from = (from); name >= name\
    \ ## __from; name--)\n\ntemplate <typename T, typename U>\nbool chmin(T& var,\
    \ U x) { if (var > x) { var = x; return true; } else return false; }\ntemplate\
    \ <typename T, typename U>\nbool chmax(T& var, U x) { if (var < x) { var = x;\
    \ return true; } else return false; }\nll power(ll e, ll t, ll mod = INF_LL) {\n\
    \  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod) if (t & 1) (res *= e) %= mod;\
    \ return res;\n}\nll choose(ll n, int r) {\n  chmin(r, n-r); if (r < 0) return\
    \ 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return res;\n}\ntemplate <typename\
    \ T, typename U> T divceil(T m, U d) { return (m + d - 1) / d; }\ntemplate <typename\
    \ T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }\ntemplate <typename...\
    \ Ts> auto make_v(size_t a, Ts... ts) {\n  return vector<decltype(make_v(ts...))>(a,\
    \ make_v(ts...));\n}\n\n// debugging stuff\n#pragma GCC diagnostic push\n#pragma\
    \ GCC diagnostic ignored \"-Wmisleading-indentation\"\n#define repi(it, ds) for\
    \ (auto it = ds.begin(); it != ds.end(); it++)\nclass DebugPrint { public: template\
    \ <typename T> DebugPrint& operator <<(const T& v) {\n#ifdef LOCAL\n    cerr <<\
    \ v;\n#endif\nreturn *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint&\
    \ os, const\nvector<T>& vec) { os << \"{\"; for (int i = 0; i < vec.size(); i++)\
    \ os << vec[i] << (i + 1 ==\nvec.size() ? \"\" : \", \"); os << \"}\"; return\
    \ os; } template <typename T, typename U> DebugPrint&\noperator<<(DebugPrint&\
    \ os, const map<T, U>& map_var) { os << \"{\"; repi(itr, map_var) { os << *\n\
    itr; itr++; if (itr != map_var.end()) os << \", \"; itr--; } os << \"}\"; return\
    \ os; } template <\ntypename T> DebugPrint& operator<<(DebugPrint& os, const set<T>&\
    \ set_var) { os << \"{\"; repi(\nitr, set_var) { os << *itr; itr++; if (itr !=\
    \ set_var.end()) os << \", \"; itr--; } os << \"}\";\nreturn os; } template <typename\
    \ T, typename U> DebugPrint& operator<<(DebugPrint& os, const\npair<T, U>& p)\
    \ { os << \"(\" << p.first << \", \" << p.second << \")\"; return os; } void dump_func(\n\
    ) { debugos << newl; } template <class Head, class... Tail> void dump_func(Head\
    \ &&head, Tail\n&&... tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos\
    \ << \", \"; } dump_func(forward\n<Tail>(tail)...); }\n#ifdef LOCAL\n#define dump(...)\
    \ debugos << \"  \" << string(#__VA_ARGS__) << \": \" << \"[\" << to_string(__LINE__)\
    \ \\\n<< \":\" << __FUNCTION__ << \"]\" << newl << \"    \", dump_func(__VA_ARGS__)\n\
    #else\n#define dump(...) ({})\n#endif\n#pragma GCC diagnostic pop\n\n\n#line 2\
    \ \"graph/graph.cpp\"\n\n#line 4 \"graph/graph.cpp\"\n\nstruct Edge {\n  int to;\
    \ ll cost;\n  Edge(int _to) : to(_to), cost(1) {}\n  Edge(int _to, ll _cost) :\
    \ to(_to), cost(_cost) {}\n  operator int() const { return to; }\n};\n\nusing\
    \ Graph = vector<vector<Edge>>;\n#line 5 \"tree/hld.cpp\"\n\nclass HLD {\n private:\n\
    \  VI index, sz, par, rev;\n  // last vertex in ascending heavy path\n  VI nxt;\n\
    \n public:\n  HLD(Graph& graph)\n      : index(graph.size()), sz(graph.size(),\
    \ 1),\n        par(graph.size(), -1), rev(graph.size()), nxt(graph.size()) {\n\
    \    dfs_sz(graph, 0);\n    dfs_hld(graph, 0);\n  }\n\n private:\n  void dfs_sz(Graph&\
    \ graph, int v) {\n    if (graph[v].size() >= 2 and graph[v][0] == par[v])\n \
    \     swap(graph[v][0], graph[v][1]);\n    for (auto& c : graph[v])\n      if\
    \ (c != par[v]) {\n        par[c] = v;\n        dfs_sz(graph, c);\n        sz[v]\
    \ += sz[c];\n        if (sz[c] > sz[graph[v][0]]) swap(c, graph[v][0]);\n    \
    \  }\n  }\n\n  void dfs_hld(const Graph& graph, int v) {\n    static int t = 0;\n\
    \    index[v] = t++;\n    rev[index[v]] = v;\n    for (auto c : graph[v])\n  \
    \    if (c != par[v]) {\n        nxt[c] = (c.to == graph[v][0].to ? nxt[v] : c.to);\n\
    \        dfs_hld(graph, c);\n      }\n    assert(sz[v] == t - index[v]);\n  }\n\
    \n public:\n  template <typename F>\n  void path_vertex(int u, int v, F f) {\n\
    \    while (true) {\n      if (index[u] > index[v]) swap(u, v);\n      // debug(u);\
    \ debug(v);\n      // debug(nxt[u]); debug(index[u]);\n      f(max(index[nxt[v]],\
    \ index[u]), index[v] + 1);\n      if (nxt[u] != nxt[v])\n        v = par[nxt[v]];\n\
    \      else\n        break;\n    }\n  }\n\n  template <typename F>\n  void path_edge(int\
    \ u, int v, F f) {\n    while (true) {\n      if (index[u] > index[v]) swap(u,\
    \ v);\n      if (nxt[u] != nxt[v]) {\n        f(index[nxt[v]], index[v] + 1);\n\
    \        v = par[nxt[v]];\n      } else {\n        if (u != v) f(index[u] + 1,\
    \ index[v] + 1);\n        break;\n      }\n    }\n  }\n\n  template <typename\
    \ F>\n  void subtree_vertex(int v, F f) {\n    f(index[v], index[v] + sz[v]);\n\
    \  }\n\n  template <typename F>\n  void subtree_edge(int v, F f) {\n    f(index[v]\
    \ + 1, index[v] + sz[v]);\n  }\n\n  int lca(int u, int v) {\n    while (1) {\n\
    \      if (index[u] > index[v]) swap(u, v);\n      if (nxt[u] == nxt[v]) return\
    \ u;\n      v = par[nxt[v]];\n    }\n  }\n\n  int subtree_size(int v) { return\
    \ sz[v]; }\n\n  int vertex(int v) { return index[v]; }\n\n  int parent(int v)\
    \ { return par[v]; }\n\n  int restore(int ix) { return rev[ix]; }\n};\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"graph/graph.cpp\"\n\
    \nclass HLD {\n private:\n  VI index, sz, par, rev;\n  // last vertex in ascending\
    \ heavy path\n  VI nxt;\n\n public:\n  HLD(Graph& graph)\n      : index(graph.size()),\
    \ sz(graph.size(), 1),\n        par(graph.size(), -1), rev(graph.size()), nxt(graph.size())\
    \ {\n    dfs_sz(graph, 0);\n    dfs_hld(graph, 0);\n  }\n\n private:\n  void dfs_sz(Graph&\
    \ graph, int v) {\n    if (graph[v].size() >= 2 and graph[v][0] == par[v])\n \
    \     swap(graph[v][0], graph[v][1]);\n    for (auto& c : graph[v])\n      if\
    \ (c != par[v]) {\n        par[c] = v;\n        dfs_sz(graph, c);\n        sz[v]\
    \ += sz[c];\n        if (sz[c] > sz[graph[v][0]]) swap(c, graph[v][0]);\n    \
    \  }\n  }\n\n  void dfs_hld(const Graph& graph, int v) {\n    static int t = 0;\n\
    \    index[v] = t++;\n    rev[index[v]] = v;\n    for (auto c : graph[v])\n  \
    \    if (c != par[v]) {\n        nxt[c] = (c.to == graph[v][0].to ? nxt[v] : c.to);\n\
    \        dfs_hld(graph, c);\n      }\n    assert(sz[v] == t - index[v]);\n  }\n\
    \n public:\n  template <typename F>\n  void path_vertex(int u, int v, F f) {\n\
    \    while (true) {\n      if (index[u] > index[v]) swap(u, v);\n      // debug(u);\
    \ debug(v);\n      // debug(nxt[u]); debug(index[u]);\n      f(max(index[nxt[v]],\
    \ index[u]), index[v] + 1);\n      if (nxt[u] != nxt[v])\n        v = par[nxt[v]];\n\
    \      else\n        break;\n    }\n  }\n\n  template <typename F>\n  void path_edge(int\
    \ u, int v, F f) {\n    while (true) {\n      if (index[u] > index[v]) swap(u,\
    \ v);\n      if (nxt[u] != nxt[v]) {\n        f(index[nxt[v]], index[v] + 1);\n\
    \        v = par[nxt[v]];\n      } else {\n        if (u != v) f(index[u] + 1,\
    \ index[v] + 1);\n        break;\n      }\n    }\n  }\n\n  template <typename\
    \ F>\n  void subtree_vertex(int v, F f) {\n    f(index[v], index[v] + sz[v]);\n\
    \  }\n\n  template <typename F>\n  void subtree_edge(int v, F f) {\n    f(index[v]\
    \ + 1, index[v] + sz[v]);\n  }\n\n  int lca(int u, int v) {\n    while (1) {\n\
    \      if (index[u] > index[v]) swap(u, v);\n      if (nxt[u] == nxt[v]) return\
    \ u;\n      v = par[nxt[v]];\n    }\n  }\n\n  int subtree_size(int v) { return\
    \ sz[v]; }\n\n  int vertex(int v) { return index[v]; }\n\n  int parent(int v)\
    \ { return par[v]; }\n\n  int restore(int ix) { return rev[ix]; }\n};\n"
  dependsOn:
  - template.cpp
  - graph/graph.cpp
  isVerificationFile: false
  path: tree/hld.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/0367.test.cpp
documentation_of: tree/hld.cpp
layout: document
redirect_from:
- /library/tree/hld.cpp
- /library/tree/hld.cpp.html
title: tree/hld.cpp
---
