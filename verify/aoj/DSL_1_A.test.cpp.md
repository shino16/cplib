---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.cpp
    title: data-structure/union-find.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"verify/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#line 2 \"template.cpp\"\n\n#ifndef LOCAL\n#pragma GCC optimize(\"O3\")\n#pragma\
    \ GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n#endif\n#include\
    \ <algorithm>\n#include <bitset>\n#include <cassert>\n#include <cmath>\n#include\
    \ <functional>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\nusing namespace std;\nusing ll =\
    \ long long;\nusing ull = unsigned long long;\nusing VI = vector<int>;\nusing\
    \ VVI = vector<vector<int>>;\nusing VLL = vector<ll>;\nusing VVLL = vector<vector<ll>>;\n\
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
    #endif\n#pragma GCC diagnostic pop\n\n\n#line 2 \"data-structure/union-find.cpp\"\
    \n\n#line 4 \"data-structure/union-find.cpp\"\n\nclass UnionFind {\n private:\n\
    \  int n, cnt;\n  vector<int> par, rank, sz;\n\n public:\n  UnionFind(int _n)\
    \ : n(_n), cnt(_n), par(_n), rank(_n), sz(_n, 1) {\n    iota(all(par), 0);\n \
    \ }\n  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }\n \
    \ void merge(int x, int y) {\n    x = root(x);\n    y = root(y);\n    if (x ==\
    \ y) return;\n    if (rank[x] < rank[y]) swap(x, y);\n    par[y] = x;\n    if\
    \ (rank[x] == rank[y]) rank[x]++;\n    sz[x] += sz[y];\n    cnt--;\n  }\n  bool\
    \ same(int x, int y) { return root(x) == root(y); }\n  int size(int x) { return\
    \ sz[root(x)]; }\n  int count() { return cnt; }\n};\n#line 1 \"util/fast-io.cpp\"\
    \n\n// IO\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wmisleading-indentation\"\
    \nclass MyScanner { public: int offset = 0; char nc(){ return getchar(); }\ntemplate\
    \ <typename T> void input_integer(T& var) { var = 0; T sign = 1; int cc = nc();\
    \ for (;\ncc < '0' || '9' < cc; cc = nc()) if (cc == '-') sign = -1; for (; '0'\
    \ <= cc && cc <= '9'; cc =\nnc()) var = (var << 3) + (var << 1) + cc - '0'; var\
    \ = var * sign; var += offset; } int c() {\nchar c; while (c = nc(), c == ' '\
    \ or c == '\\n'); return c; } MyScanner& operator>>(char& var)\n{ var = c(); return\
    \ *this; } MyScanner& operator>>(int& var) { input_integer<int>(var); return\n\
    *this; } MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this;\
    \ } MyScanner&\noperator>>(string& var) { var = \"\"; int cc = nc(); for (; !isgraph(cc);\
    \ cc = nc()); for\n(; isgraph(cc); cc = nc()) var.push_back(cc); return *this;\
    \ } template <size_t N>\nMyScanner& operator>>(bitset<N>& var) { ll v; input_integer<ll>(v);\
    \ var = bitset<N>(v); return\n*this; } template <typename T> operator T() { T\
    \ x; *this >> x; return x; } template <typename\nT> void operator()(T &t) { *this\
    \ >> t; } template <typename T, typename... Ts> void operator()\n(T &t, Ts &...ts)\
    \ { *this >> t; this->operator()(ts...); } template <typename Iter> void iter\n\
    (Iter first, Iter last) { while (first != last) *this >> *first, first++; } VI\
    \ vi(int n) { VI\nres(n); iter(all(res)); return res; } VVI vvi(int n, int m)\
    \ { VVI res(n); rep(i, n) res[i] =\nvi(m); return res; } VLL vll(int n) { VLL\
    \ res(n); iter(all(res)); return res; } VVLL vvll(int\nn, int m) { VVLL res(n);\
    \ rep(i, n) res[i] = vll(m); return res; } template <typename T> vector\n<T> v(int\
    \ n) { vector<T> res(n); iter(all(res)); return res; } } IN, IN1{-1}; class MyPrinter\n\
    { public: int offset = 0; template <typename T> void output_integer(T var) { var\
    \ += offset; if\n(var == 0) { putchar('0'); return; } if (var < 0) putchar('-'),\
    \ var = -var; char stack[32];\nint stack_p = 0; while (var) stack[stack_p++] =\
    \ '0' + (var % 10), var /= 10; while (stack_p)\nputchar(stack[--stack_p]); } MyPrinter&\
    \ operator<<(char c) { putchar(c); return *this; }\nMyPrinter& operator<<(double\
    \ x) { printf(\"%.10f\", x); return *this; } template <typename T>\nMyPrinter&\
    \ operator<<(T var) { output_integer<T>(var); return *this; } MyPrinter& operator<<(\n\
    char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; } MyPrinter&\
    \ operator<<(const\nchar* str_p) { while (*str_p) putchar(*(str_p++)); return\
    \ *this; } MyPrinter& operator<<(const\nstring& str) { const char* p = str.c_str();\
    \ const char* l = p + str.size(); while (p < l)\nputchar(*p++); return *this;\
    \ } template <typename T> void operator()(T x) { *this << x << newl\n; } template\
    \ <typename T, typename... Ts> void operator()(T x, Ts ...xs) { *this << x <<\
    \ \" \";\nthis->operator()(xs...); } template <typename Iter> void iter(Iter s,\
    \ Iter t) { if (s == t) *\nthis << \"\\n\"; else for (; s != t; s++) *this <<\
    \ *s << \" \\n\"[next(s, 1) == t]; } } OUT, OUT1{1}\n; template <typename T, typename\
    \ U> MyPrinter& operator<<(MyPrinter& out, const pair<T, U>&\nvar) { return out\
    \ << var.first << \" \" << var.second; } template <typename Tuple, size_t I,\n\
    size_t N, enable_if_t<I == N>* = nullptr> MyPrinter& tuple_impl(MyPrinter& out,\
    \ const Tuple&\nvar) { return out; } template <typename Tuple, size_t I, size_t\
    \ N, enable_if_t<I != N>* =\nnullptr> MyPrinter& tuple_impl(MyPrinter& out, const\
    \ Tuple& var) { out << get<I>(var) << \" \";\nreturn tuple_impl<Tuple, I+1, N>(out,\
    \ var); } template <typename... Ts> MyPrinter& operator<<(\nMyPrinter& out, const\
    \ tuple<Ts...>& var) { return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(\nout,\
    \ var); } template <typename T, typename U> MyScanner& operator>>(MyScanner& in,\
    \ pair<T, U>\n& var) { return in >> var.first >> var.second; } template <typename\
    \ Tuple, size_t I, size_t N,\nenable_if_t<I == N>* = nullptr> MyScanner& tuple_impl(MyScanner&\
    \ in, Tuple& var) { return in;\n} template <typename Tuple, size_t I, size_t N,\
    \ enable_if_t<I != N>* = nullptr> MyScanner&\ntuple_impl(MyScanner& in, Tuple&\
    \ var) { in >> get<I>(var); return tuple_impl<Tuple, I+1, N>(in\n, var); } template\
    \ <typename... Ts> MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) {\n\
    return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var); }\n#pragma GCC diagnostic\
    \ pop\n#line 5 \"verify/aoj/DSL_1_A.test.cpp\"\n\nint main() {\n  int n = IN,\
    \ q = IN;\n  UnionFind uf(n);\n  rep(q) {\n    int c = IN, x = IN, y = IN;\n \
    \   if (c == 0) uf.merge(x, y);\n    else OUT((int)uf.same(x, y));\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include \"template.cpp\"\n#include \"data-structure/union-find.cpp\"\n#include\
    \ \"util/fast-io.cpp\"\n\nint main() {\n  int n = IN, q = IN;\n  UnionFind uf(n);\n\
    \  rep(q) {\n    int c = IN, x = IN, y = IN;\n    if (c == 0) uf.merge(x, y);\n\
    \    else OUT((int)uf.same(x, y));\n  }\n}\n"
  dependsOn:
  - template.cpp
  - data-structure/union-find.cpp
  - util/fast-io.cpp
  isVerificationFile: true
  path: verify/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_1_A.test.cpp
- /verify/verify/aoj/DSL_1_A.test.cpp.html
title: verify/aoj/DSL_1_A.test.cpp
---
