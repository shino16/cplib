---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: graph/graph.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: util/fix.cpp
    title: util/fix.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/lca.cpp
    title: tree/lca.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/dfs.cpp\"\n\n#line 2 \"template.cpp\"\n\n#ifndef LOCAL\n\
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
    \ Graph = vector<vector<Edge>>;\n#line 2 \"util/fix.cpp\"\n\n#line 4 \"util/fix.cpp\"\
    \n\ntemplate <typename F>\nclass FixPoint : private F {\n public:\n  explicit\
    \ constexpr FixPoint(F&& f) : F(forward<F>(f)) {}\n\n  template <typename... Args>\n\
    \  constexpr decltype(auto) operator()(Args&&... args) const {\n    return F::operator()(*this,\
    \ forward<Args>(args)...);\n  }\n};\n\ntemplate <typename F> decltype(auto) fix(F&&\
    \ f) noexcept {\n  return FixPoint<F>{forward<F>(f)};\n}\n#line 6 \"tree/dfs.cpp\"\
    \n\nstruct DFS {\n  VI subtree_sz, par;\n  VLL dist;\n};\n\n// tree\nDFS dfs(const\
    \ Graph& graph, int root = 0) {\n  int n = graph.size();\n  DFS res;\n  res.subtree_sz\
    \ = VI(n, 1);\n  res.par = VI(n, -1);\n  res.dist = VLL(n, INF_LL);\n  res.dist[root]\
    \ = 0;\n  fix([&](auto f, auto v)->void{\n    for (auto e : graph[v])\n      if\
    \ (e.to != res.par[v])\n        res.dist[e.to] = res.dist[v] + e.cost,\n     \
    \   res.par[e.to] = v,\n        f(e.to),\n        res.subtree_sz[v] += res.subtree_sz[e.to];\n\
    \  })(root);\n  return res;\n}\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"graph/graph.cpp\"\n\
    #include \"util/fix.cpp\"\n\nstruct DFS {\n  VI subtree_sz, par;\n  VLL dist;\n\
    };\n\n// tree\nDFS dfs(const Graph& graph, int root = 0) {\n  int n = graph.size();\n\
    \  DFS res;\n  res.subtree_sz = VI(n, 1);\n  res.par = VI(n, -1);\n  res.dist\
    \ = VLL(n, INF_LL);\n  res.dist[root] = 0;\n  fix([&](auto f, auto v)->void{\n\
    \    for (auto e : graph[v])\n      if (e.to != res.par[v])\n        res.dist[e.to]\
    \ = res.dist[v] + e.cost,\n        res.par[e.to] = v,\n        f(e.to),\n    \
    \    res.subtree_sz[v] += res.subtree_sz[e.to];\n  })(root);\n  return res;\n\
    }\n"
  dependsOn:
  - template.cpp
  - graph/graph.cpp
  - util/fix.cpp
  isVerificationFile: false
  path: tree/dfs.cpp
  requiredBy:
  - tree/lca.cpp
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/dfs.cpp
layout: document
redirect_from:
- /library/tree/dfs.cpp
- /library/tree/dfs.cpp.html
title: tree/dfs.cpp
---
