---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-heap.cpp
    title: data-structure/binary-heap.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: graph/dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.cpp
    title: graph/graph.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: util/fast-io.cpp
    title: util/fast-io.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
  bundledCode: "#line 1 \"verify/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \n\n#line 2 \"template.cpp\"\n\n#ifndef LOCAL\n#pragma GCC optimize(\"O3\")\n\
    #pragma GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n#endif\n\
    #include <algorithm>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n\
    #include <functional>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <set>\n#include <stack>\nusing namespace std;\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing VI = vector<int>;\n\
    using VVI = vector<vector<int>>;\nusing VLL = vector<ll>;\nusing VVLL = vector<vector<ll>>;\n\
    using VB = vector<bool>;\nusing PII = pair<int, int>;\nusing PLL = pair<ll, ll>;\n\
    constexpr int INF = 1000000007;\nconstexpr ll INF_LL = 1'000'000'000'000'000'007;\n\
    #define all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n#define newl\
    \ '\\n'\n\n// loops rep(until) / rep(var, until) / rep(var, from, until) / repr\
    \ (reversed order)\n#define OVERLOAD3(_1, _2, _3, name, ...) name\n#define rep(...)\
    \ OVERLOAD3(__VA_ARGS__, REPEAT_FROM_UNTIL, REPEAT_UNTIL, REPEAT)(__VA_ARGS__)\n\
    #define REPEAT(times) REPEAT_CNT(_repeat, __COUNTER__, times)\n#define REPEAT_CNT(_repeat,\
    \ cnt, times) REPEAT_CNT_CAT(_repeat, cnt, times)\n#define REPEAT_CNT_CAT(_repeat,\
    \ cnt, times) REPEAT_FROM_UNTIL(_repeat ## cnt, 0, times)\n#define REPEAT_UNTIL(name,\
    \ times) REPEAT_FROM_UNTIL(name, 0, times)\n#define REPEAT_FROM_UNTIL(name, from,\
    \ until) for (int name = from, name ## __until = (until); name < name ## __until;\
    \ name++)\n#define repr(...) OVERLOAD3(__VA_ARGS__, REPR_FROM_UNTIL, REPR_UNTIL,\
    \ REPEAT)(__VA_ARGS__)\n#define REPR_UNTIL(name, times) REPR_FROM_UNTIL(name,\
    \ 0, times)\n#define REPR_FROM_UNTIL(name, from, until) for (int name = (until)-1,\
    \ name ## __from = (from); name >= name ## __from; name--)\n\ntemplate <typename\
    \ T, typename U>\nbool chmin(T& var, U x) { if (var > x) { var = x; return true;\
    \ } else return false; }\ntemplate <typename T, typename U>\nbool chmax(T& var,\
    \ U x) { if (var < x) { var = x; return true; } else return false; }\nll power(ll\
    \ e, ll t, ll mod = INF_LL) {\n  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod)\
    \ if (t & 1) (res *= e) %= mod; return res;\n}\nll choose(ll n, int r) {\n  chmin(r,\
    \ n-r); if (r < 0) return 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return\
    \ res;\n}\ntemplate <typename T, typename U> T divceil(T m, U d) { return (m +\
    \ d - 1) / d; }\ntemplate <typename T> vector<T> make_v(size_t a, T b) { return\
    \ vector<T>(a, b); }\ntemplate <typename... Ts> auto make_v(size_t a, Ts... ts)\
    \ {\n  return vector<decltype(make_v(ts...))>(a, make_v(ts...));\n}\n\n// debugging\
    \ stuff\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wmisleading-indentation\"\
    \n#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)\nclass\
    \ DebugPrint { public: template <typename T> DebugPrint& operator <<(const T&\
    \ v) {\n#ifdef LOCAL\n    cerr << v;\n#endif\nreturn *this; } } debugos; template\
    \ <typename T> DebugPrint& operator<<(DebugPrint& os, const\nvector<T>& vec) {\
    \ os << \"{\"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==\n\
    vec.size() ? \"\" : \", \"); os << \"}\"; return os; } template <typename T, typename\
    \ U> DebugPrint&\noperator<<(DebugPrint& os, const map<T, U>& map_var) { os <<\
    \ \"{\"; repi(itr, map_var) { os << *\nitr; itr++; if (itr != map_var.end()) os\
    \ << \", \"; itr--; } os << \"}\"; return os; } template <\ntypename T> DebugPrint&\
    \ operator<<(DebugPrint& os, const set<T>& set_var) { os << \"{\"; repi(\nitr,\
    \ set_var) { os << *itr; itr++; if (itr != set_var.end()) os << \", \"; itr--;\
    \ } os << \"}\";\nreturn os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint&\
    \ os, const\npair<T, U>& p) { os << \"(\" << p.first << \", \" << p.second <<\
    \ \")\"; return os; } void dump_func(\n) { debugos << newl; } template <class\
    \ Head, class... Tail> void dump_func(Head &&head, Tail\n&&... tail) { debugos\
    \ << head; if (sizeof...(Tail) > 0) { debugos << \", \"; } dump_func(forward\n\
    <Tail>(tail)...); }\n#ifdef LOCAL\n#define dump(...) debugos << \"  \" << string(#__VA_ARGS__)\
    \ << \": \" << \"[\" << to_string(__LINE__) \\\n<< \":\" << __FUNCTION__ << \"\
    ]\" << newl << \"    \", dump_func(__VA_ARGS__)\n#else\n#define dump(...) ({})\n\
    #endif\n#pragma GCC diagnostic pop\n\n\n#line 2 \"graph/dijkstra.cpp\"\n\n#line\
    \ 2 \"graph/graph.cpp\"\n\n#line 4 \"graph/graph.cpp\"\n\nstruct Edge {\n  int\
    \ to; ll cost;\n  Edge(int _to) : to(_to), cost(1) {}\n  Edge(int _to, ll _cost)\
    \ : to(_to), cost(_cost) {}\n  operator int() const { return to; }\n};\n\nusing\
    \ Graph = vector<vector<Edge>>;\n#line 2 \"data-structure/binary-heap.cpp\"\n\n\
    #line 4 \"data-structure/binary-heap.cpp\"\n\ntemplate <typename T, typename Compare\
    \ = less<>>\nclass BinaryHeap {\n private:\n  vector<T> data;\n  vector<int> index,\
    \ handle;\n  const Compare comp;\n\n public:\n  BinaryHeap(Compare comp_ = {})\
    \ : comp(comp_) {}\n  template <typename Iter>\n  BinaryHeap(Iter first, Iter\
    \ last, Compare comp_ = {}) : comp(comp_) {\n    data.insert(data.end(), first,\
    \ last);\n    index.resize(data.size());\n    handle.resize(data.size());\n  \
    \  iota(all(index), 0);\n    iota(all(handle), 0);\n    repr(i, divceil(data.size(),\
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
    #line 1 \"util/fast-io.cpp\"\n\n// IO\n#pragma GCC diagnostic push\n#pragma GCC\
    \ diagnostic ignored \"-Wmisleading-indentation\"\nclass MyScanner { public: int\
    \ offset = 0; char nc(){ return getchar(); }\ntemplate <typename T> void input_integer(T&\
    \ var) { var = 0; T sign = 1; int cc = nc(); for (;\ncc < '0' || '9' < cc; cc\
    \ = nc()) if (cc == '-') sign = -1; for (; '0' <= cc && cc <= '9'; cc =\nnc())\
    \ var = (var << 3) + (var << 1) + cc - '0'; var = var * sign; var += offset; }\
    \ int c() {\nchar c; while (c = nc(), c == ' ' or c == '\\n'); return c; } MyScanner&\
    \ operator>>(char& var)\n{ var = c(); return *this; } MyScanner& operator>>(int&\
    \ var) { input_integer<int>(var); return\n*this; } MyScanner& operator>>(ll& var)\
    \ { input_integer<ll>(var); return *this; } MyScanner&\noperator>>(string& var)\
    \ { var = \"\"; int cc = nc(); for (; !isgraph(cc); cc = nc()); for\n(; isgraph(cc);\
    \ cc = nc()) var.push_back(cc); return *this; } template <size_t N>\nMyScanner&\
    \ operator>>(bitset<N>& var) { ll v; input_integer<ll>(v); var = bitset<N>(v);\
    \ return\n*this; } template <typename T> operator T() { T x; *this >> x; return\
    \ x; } template <typename\nT> void operator()(T &t) { *this >> t; } template <typename\
    \ T, typename... Ts> void operator()\n(T &t, Ts &...ts) { *this >> t; this->operator()(ts...);\
    \ } template <typename Iter> void iter\n(Iter first, Iter last) { while (first\
    \ != last) *this >> *first, first++; } VI vi(int n) { VI\nres(n); iter(all(res));\
    \ return res; } VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] =\nvi(m);\
    \ return res; } VLL vll(int n) { VLL res(n); iter(all(res)); return res; } VVLL\
    \ vvll(int\nn, int m) { VVLL res(n); rep(i, n) res[i] = vll(m); return res; }\
    \ template <typename T> vector\n<T> v(int n) { vector<T> res(n); iter(all(res));\
    \ return res; } } IN, IN1{-1}; class MyPrinter\n{ public: int offset = 0; template\
    \ <typename T> void output_integer(T var) { var += offset; if\n(var == 0) { putchar('0');\
    \ return; } if (var < 0) putchar('-'), var = -var; char stack[32];\nint stack_p\
    \ = 0; while (var) stack[stack_p++] = '0' + (var % 10), var /= 10; while (stack_p)\n\
    putchar(stack[--stack_p]); } MyPrinter& operator<<(char c) { putchar(c); return\
    \ *this; }\nMyPrinter& operator<<(double x) { printf(\"%.10f\", x); return *this;\
    \ } template <typename T>\nMyPrinter& operator<<(T var) { output_integer<T>(var);\
    \ return *this; } MyPrinter& operator<<(\nchar* str_p) { while (*str_p) putchar(*(str_p++));\
    \ return *this; } MyPrinter& operator<<(const\nchar* str_p) { while (*str_p) putchar(*(str_p++));\
    \ return *this; } MyPrinter& operator<<(const\nstring& str) { const char* p =\
    \ str.c_str(); const char* l = p + str.size(); while (p < l)\nputchar(*p++); return\
    \ *this; } template <typename T> void operator()(T x) { *this << x << newl\n;\
    \ } template <typename T, typename... Ts> void operator()(T x, Ts ...xs) { *this\
    \ << x << \" \";\nthis->operator()(xs...); } template <typename Iter> void iter(Iter\
    \ s, Iter t) { if (s == t) *\nthis << \"\\n\"; else for (; s != t; s++) *this\
    \ << *s << \" \\n\"[next(s, 1) == t]; } } OUT, OUT1{1}\n; template <typename T,\
    \ typename U> MyPrinter& operator<<(MyPrinter& out, const pair<T, U>&\nvar) {\
    \ return out << var.first << \" \" << var.second; } template <typename Tuple,\
    \ size_t I,\nsize_t N, enable_if_t<I == N>* = nullptr> MyPrinter& tuple_impl(MyPrinter&\
    \ out, const Tuple&\nvar) { return out; } template <typename Tuple, size_t I,\
    \ size_t N, enable_if_t<I != N>* =\nnullptr> MyPrinter& tuple_impl(MyPrinter&\
    \ out, const Tuple& var) { out << get<I>(var) << \" \";\nreturn tuple_impl<Tuple,\
    \ I+1, N>(out, var); } template <typename... Ts> MyPrinter& operator<<(\nMyPrinter&\
    \ out, const tuple<Ts...>& var) { return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(\n\
    out, var); } template <typename T, typename U> MyScanner& operator>>(MyScanner&\
    \ in, pair<T, U>\n& var) { return in >> var.first >> var.second; } template <typename\
    \ Tuple, size_t I, size_t N,\nenable_if_t<I == N>* = nullptr> MyScanner& tuple_impl(MyScanner&\
    \ in, Tuple& var) { return in;\n} template <typename Tuple, size_t I, size_t N,\
    \ enable_if_t<I != N>* = nullptr> MyScanner&\ntuple_impl(MyScanner& in, Tuple&\
    \ var) { in >> get<I>(var); return tuple_impl<Tuple, I+1, N>(in\n, var); } template\
    \ <typename... Ts> MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) {\n\
    return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var); }\n#pragma GCC diagnostic\
    \ pop\n#line 6 \"verify/aoj/GRL_1_A.test.cpp\"\n\nint main() {\n  int n = IN,\
    \ m = IN, r = IN;\n  Graph graph(n);\n  rep(m) {\n    int u = IN, v = IN, d =\
    \ IN;\n    graph[u].emplace_back(v, d);\n  }\n  auto d = dijkstra(graph, r);\n\
    \  rep(i, n) OUT(d[i] >= INF ? \"INF\" : to_string(d[i]));\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \n\n#include \"template.cpp\"\n#include \"graph/dijkstra.cpp\"\n#include \"util/fast-io.cpp\"\
    \n\nint main() {\n  int n = IN, m = IN, r = IN;\n  Graph graph(n);\n  rep(m) {\n\
    \    int u = IN, v = IN, d = IN;\n    graph[u].emplace_back(v, d);\n  }\n  auto\
    \ d = dijkstra(graph, r);\n  rep(i, n) OUT(d[i] >= INF ? \"INF\" : to_string(d[i]));\n\
    }"
  dependsOn:
  - template.cpp
  - graph/dijkstra.cpp
  - graph/graph.cpp
  - data-structure/binary-heap.cpp
  - util/fast-io.cpp
  isVerificationFile: true
  path: verify/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/GRL_1_A.test.cpp
- /verify/verify/aoj/GRL_1_A.test.cpp.html
title: verify/aoj/GRL_1_A.test.cpp
---
