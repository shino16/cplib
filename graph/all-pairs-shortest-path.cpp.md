---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-heap.cpp
    title: data-structure/binary-heap.cpp
  - icon: ':warning:'
    path: graph/bellman-ford.cpp
    title: graph/bellman-ford.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: graph/dijkstra.cpp
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
  bundledCode: "#line 2 \"graph/all-pairs-shortest-path.cpp\"\n\n#line 2 \"template.cpp\"\
    \n\n#ifndef LOCAL\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#pragma GCC target(\"avx\")\n#endif\n#include <algorithm>\n#include <bitset>\n\
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
    \ \"graph/bellman-ford.cpp\"\n\n#line 2 \"graph/graph.cpp\"\n\n#line 4 \"graph/graph.cpp\"\
    \n\nstruct Edge {\n  int to; ll cost;\n  Edge(int _to) : to(_to), cost(1) {}\n\
    \  Edge(int _to, ll _cost) : to(_to), cost(_cost) {}\n  operator int() const {\
    \ return to; }\n};\n\nusing Graph = vector<vector<Edge>>;\n#line 5 \"graph/bellman-ford.cpp\"\
    \n\n// empty if the given graph has a negative cycle\nVLL bellman_ford(const Graph&\
    \ graph, int start) {\n  int n = graph.size();\n  VLL dist(n, INF_LL);\n  dist[start]\
    \ = 0;\n  rep(n) {\n    bool upd = false;\n    rep(v, n) for (auto e : graph[v])\
    \ upd |= chmin(dist[e.to], dist[v] + e.cost);\n    if (not upd) return dist;\n\
    \  }\n  return {};\n}\n#line 2 \"graph/dijkstra.cpp\"\n\n#line 2 \"data-structure/binary-heap.cpp\"\
    \n\n#line 4 \"data-structure/binary-heap.cpp\"\n\ntemplate <typename T, typename\
    \ Compare = less<>>\nclass BinaryHeap {\n private:\n  vector<T> data;\n  vector<int>\
    \ index, handle;\n  const Compare comp;\n\n public:\n  BinaryHeap(Compare comp_\
    \ = {}) : comp(comp_) {}\n  template <typename Iter>\n  BinaryHeap(Iter first,\
    \ Iter last, Compare comp_ = {}) : comp(comp_) {\n    data.insert(data.end(),\
    \ first, last);\n    index.resize(data.size());\n    handle.resize(data.size());\n\
    \    iota(all(index), 0);\n    iota(all(handle), 0);\n    repr(i, divceil(data.size(),\
    \ 2)) pushdown(i);\n  }\n\n private:\n  void rotate(int i, int j) {\n    swap(data[i],\
    \ data[j]);\n    swap(index[i], index[j]);\n    swap(handle[index[i]], handle[index[j]]);\n\
    \  }\n\n  void pushup(int i) {\n    int j;\n    while (j = (i - 1) / 2, comp(data[j],\
    \ data[i])) rotate(i, j), i = j;\n  }\n\n  void pushdown(int i) {\n    int j;\n\
    \    while (j = (i + 1) * 2, j < data.size()) {\n      if (comp(data[j], data[j\
    \ - 1])) j--;\n      rotate(i, j), i = j;\n    }\n    j = i * 2 + 1;\n    if (j\
    \ < data.size() and comp(data[i], data[j])) rotate(i, j);\n  }\n\n public:\n \
    \ bool empty() { return data.empty(); }\n\n  void push(int i, const T& v) { emplace(i,\
    \ v); }\n  void push(int i, T&& v) { emplace(i, move(v)); }\n\n  template <typename...\
    \ Args>\n  void emplace(int i, Args&&... args) {\n    if (i >= handle.size())\
    \ {\n      int s = handle.size();\n      handle.resize(i + 1);\n      fill(handle.begin()\
    \ + s, handle.end(), -1);\n    }\n    handle[i] = data.size();\n    data.emplace_back(forward<Args>(args)...);\n\
    \    index.push_back(i);\n    pushup(handle[i]);\n  }\n\n  T& top() { return data[0];\
    \ }\n  int top_index() { return index[0]; }\n\n  void pop() { remove(0); }\n\n\
    \  void remove(int i) {\n    if (i != data.size() - 1) rotate(i, data.size() -\
    \ 1);\n    data.pop_back();\n    handle[index.back()] = -1;\n    index.pop_back();\n\
    \    pushdown(i);\n  }\n\n  template <typename... Args>\n  void prioritize(int\
    \ i, Args&&... args) {\n    if (i >= handle.size() or handle[i] == -1)\n     \
    \ emplace(i, forward<Args>(args)...);\n    else {\n      data[handle[i]] = T(forward<Args>(args)...);\n\
    \      pushup(handle[i]);\n      pushdown(handle[i]);\n    }\n  }\n};\n#line 6\
    \ \"graph/dijkstra.cpp\"\n\nvector<ll> dijkstra(const Graph& graph, int start)\
    \ {\n  BinaryHeap<ll, greater<>> hp;\n  vector<ll> dist(graph.size(), INF_LL);\n\
    \  dist[start] = 0;\n  hp.emplace(start, 0);\n\n  while (not hp.empty()) {\n \
    \   ll d = hp.top();\n    int v = hp.top_index();\n    hp.pop();\n    if (dist[v]\
    \ < d) continue;\n    for (auto e : graph[v]) {\n      if (chmin(dist[e.to], dist[v]\
    \ + e.cost)) hp.prioritize(e.to, dist[e.to]);\n    }\n  }\n  return dist;\n}\n\
    #line 6 \"graph/all-pairs-shortest-path.cpp\"\n\n\n// no negative cycle please\n\
    VVLL all_pairs_shortest_path(Graph& graph) {\n  int n = graph.size();\n  VLL potential\
    \ = bellman_ford(graph, 0);\n  rep(v, n) for (auto e : graph[v])\n      e.cost\
    \ += potential[v] - potential[e.to];\n  VVLL res(n);\n  rep(start, n) {\n    res[start]\
    \ = dijkstra(graph, start);\n    rep(to, n)\n      if (res[start][to] >= INF_LL\
    \ / 8) res[start][to] = INF_LL;\n      else res[start][to] += potential[to] -\
    \ potential[start];\n  }\n  rep(v, n) for (auto e : graph[v])\n      e.cost -=\
    \ potential[v] - potential[e.to];\n  return res;\n}\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"graph/bellman-ford.cpp\"\
    \n#include \"graph/dijkstra.cpp\"\n\n\n// no negative cycle please\nVVLL all_pairs_shortest_path(Graph&\
    \ graph) {\n  int n = graph.size();\n  VLL potential = bellman_ford(graph, 0);\n\
    \  rep(v, n) for (auto e : graph[v])\n      e.cost += potential[v] - potential[e.to];\n\
    \  VVLL res(n);\n  rep(start, n) {\n    res[start] = dijkstra(graph, start);\n\
    \    rep(to, n)\n      if (res[start][to] >= INF_LL / 8) res[start][to] = INF_LL;\n\
    \      else res[start][to] += potential[to] - potential[start];\n  }\n  rep(v,\
    \ n) for (auto e : graph[v])\n      e.cost -= potential[v] - potential[e.to];\n\
    \  return res;\n}\n"
  dependsOn:
  - template.cpp
  - graph/bellman-ford.cpp
  - graph/graph.cpp
  - graph/dijkstra.cpp
  - data-structure/binary-heap.cpp
  isVerificationFile: false
  path: graph/all-pairs-shortest-path.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/all-pairs-shortest-path.cpp
layout: document
redirect_from:
- /library/graph/all-pairs-shortest-path.cpp
- /library/graph/all-pairs-shortest-path.cpp.html
title: graph/all-pairs-shortest-path.cpp
---
