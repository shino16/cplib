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
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.cpp\"\n\n#line 2 \"template.cpp\"\n\n#ifndef\
    \ LOCAL\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\
    #pragma GCC target(\"avx\")\n#endif\n#include <algorithm>\n#include <bitset>\n\
    #include <cassert>\n#include <cmath>\n#include <functional>\n#include <iostream>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\nusing namespace std;\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing VI = vector<int>;\nusing VVI = vector<vector<int>>;\nusing VLL\
    \ = vector<ll>;\nusing VVLL = vector<vector<ll>>;\nusing VB = vector<bool>;\n\
    using PII = pair<int, int>;\nusing PLL = pair<ll, ll>;\nconstexpr int INF = 1000000007;\n\
    constexpr ll INF_LL = 1'000'000'000'000'000'007;\n#define all(x) begin(x), end(x)\n\
    #define rall(x) rbegin(x), rend(x)\n#define newl '\\n'\n\n// loops rep(until)\
    \ / rep(var, until) / rep(var, from, until) / repr (reversed order)\n#define OVERLOAD3(_1,\
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
    \ Graph = vector<vector<Edge>>;\n#line 5 \"tree/rerooting.cpp\"\n\n#pragma GCC\
    \ diagnostic push\n#pragma GCC diagnostic ignored \"-Wshadow\"\ntemplate <typename\
    \ T, typename Edge, typename Apply, typename Merge>\nclass ReRooting {\npublic:\n\
    \  struct Node {\n    int to, rev;\n    Edge data;\n    Node(int to, Edge data)\
    \ : to(to), data(data) {}\n    bool operator<(const Node &v) const { return to\
    \ < v.to; };\n  };\n\nprivate:\n  vector<vector<Node>> G;\n  vector<vector<T>>\
    \ ld, rd;\n  vector<int> lp, rp;\n\n  const T id;\n  const Apply apply;\n  const\
    \ Merge merge;\n\npublic:\n  ReRooting(int n, T id, const Apply &apply = Apply(),\n\
    \            const Merge &merge = Merge())\n      : G(n), ld(n), rd(n), lp(n),\
    \ rp(n), id(id), apply(apply), merge(merge) {}\n\n  // d: propagate v to u\n \
    \ void add_edge(int u, int v, Edge d, Edge e) {\n    G[u].emplace_back(v, d);\n\
    \    G[v].emplace_back(u, e);\n  }\n\n  void add_edge(int u, int v, Edge d) {\
    \ add_edge(u, v, d, d); }\n\nprivate:\n  // k: idx for edge (not vertex)\n  T\
    \ dfs(int v, int k) {\n    while (lp[v] != k and lp[v] < (int)G[v].size()) {\n\
    \      const auto &e = G[v][lp[v]];\n      ld[v][lp[v] + 1] = merge(ld[v][lp[v]],\
    \ apply(dfs(e.to, e.rev), e.data));\n      lp[v]++;\n    }\n    if (k < 0) return\
    \ ld[v].back();\n    while (rp[v] != k and rp[v] >= 0) {\n      const auto &e\
    \ = G[v][rp[v]];\n      rd[v][rp[v]] = merge(rd[v][rp[v] + 1], apply(dfs(e.to,\
    \ e.rev), e.data));\n      rp[v]--;\n    }\n    return merge(ld[v][k], rd[v][k\
    \ + 1]);\n  }\n\n  int search(vector<Node> &vs, int idx) {\n    return lower_bound(all(vs),\
    \ Node(idx, vs[0].data)) - vs.begin();\n  }\n\npublic:\n  vector<T> build() {\n\
    \    int n = G.size();\n    for (int i = 0; i < n; i++) {\n      sort(all(G[i]));\n\
    \      ld[i].assign((int)G[i].size() + 1, id);\n      rd[i].assign((int)G[i].size()\
    \ + 1, id);\n      lp[i] = 0;\n      rp[i] = (int)G[i].size() - 1;\n    }\n\n\
    \    for (int i = 0; i < n; i++)\n      for (Node &t : G[i]) t.rev = search(G[t.to],\
    \ i);\n\n    vector<T> res;\n    for (int i = 0; i < n; i++) res.emplace_back(dfs(i,\
    \ -1));\n\n    return res;\n  }\n\n  // p: idx for vertex\n  T subtree(int v,\
    \ int p) {\n    int k = search(G[p], v);\n    assert(k < (int)G[p].size() and\
    \ G[p][k].to == v);\n    return apply(dfs(v, G[p][k].rev), G[p][k].data);\n  }\n\
    };\n#pragma GCC diagnostic pop\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"graph/graph.cpp\"\n\
    \n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wshadow\"\ntemplate\
    \ <typename T, typename Edge, typename Apply, typename Merge>\nclass ReRooting\
    \ {\npublic:\n  struct Node {\n    int to, rev;\n    Edge data;\n    Node(int\
    \ to, Edge data) : to(to), data(data) {}\n    bool operator<(const Node &v) const\
    \ { return to < v.to; };\n  };\n\nprivate:\n  vector<vector<Node>> G;\n  vector<vector<T>>\
    \ ld, rd;\n  vector<int> lp, rp;\n\n  const T id;\n  const Apply apply;\n  const\
    \ Merge merge;\n\npublic:\n  ReRooting(int n, T id, const Apply &apply = Apply(),\n\
    \            const Merge &merge = Merge())\n      : G(n), ld(n), rd(n), lp(n),\
    \ rp(n), id(id), apply(apply), merge(merge) {}\n\n  // d: propagate v to u\n \
    \ void add_edge(int u, int v, Edge d, Edge e) {\n    G[u].emplace_back(v, d);\n\
    \    G[v].emplace_back(u, e);\n  }\n\n  void add_edge(int u, int v, Edge d) {\
    \ add_edge(u, v, d, d); }\n\nprivate:\n  // k: idx for edge (not vertex)\n  T\
    \ dfs(int v, int k) {\n    while (lp[v] != k and lp[v] < (int)G[v].size()) {\n\
    \      const auto &e = G[v][lp[v]];\n      ld[v][lp[v] + 1] = merge(ld[v][lp[v]],\
    \ apply(dfs(e.to, e.rev), e.data));\n      lp[v]++;\n    }\n    if (k < 0) return\
    \ ld[v].back();\n    while (rp[v] != k and rp[v] >= 0) {\n      const auto &e\
    \ = G[v][rp[v]];\n      rd[v][rp[v]] = merge(rd[v][rp[v] + 1], apply(dfs(e.to,\
    \ e.rev), e.data));\n      rp[v]--;\n    }\n    return merge(ld[v][k], rd[v][k\
    \ + 1]);\n  }\n\n  int search(vector<Node> &vs, int idx) {\n    return lower_bound(all(vs),\
    \ Node(idx, vs[0].data)) - vs.begin();\n  }\n\npublic:\n  vector<T> build() {\n\
    \    int n = G.size();\n    for (int i = 0; i < n; i++) {\n      sort(all(G[i]));\n\
    \      ld[i].assign((int)G[i].size() + 1, id);\n      rd[i].assign((int)G[i].size()\
    \ + 1, id);\n      lp[i] = 0;\n      rp[i] = (int)G[i].size() - 1;\n    }\n\n\
    \    for (int i = 0; i < n; i++)\n      for (Node &t : G[i]) t.rev = search(G[t.to],\
    \ i);\n\n    vector<T> res;\n    for (int i = 0; i < n; i++) res.emplace_back(dfs(i,\
    \ -1));\n\n    return res;\n  }\n\n  // p: idx for vertex\n  T subtree(int v,\
    \ int p) {\n    int k = search(G[p], v);\n    assert(k < (int)G[p].size() and\
    \ G[p][k].to == v);\n    return apply(dfs(v, G[p][k].rev), G[p][k].data);\n  }\n\
    };\n#pragma GCC diagnostic pop\n"
  dependsOn:
  - template.cpp
  - graph/graph.cpp
  isVerificationFile: false
  path: tree/rerooting.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/rerooting.cpp
layout: document
redirect_from:
- /library/tree/rerooting.cpp
- /library/tree/rerooting.cpp.html
title: tree/rerooting.cpp
---
