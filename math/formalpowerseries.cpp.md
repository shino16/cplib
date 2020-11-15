---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/formalpowerseries.cpp\"\n\n#line 2 \"template.cpp\"\
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
    #else\n#define dump(...) ({})\n#endif\n#pragma GCC diagnostic pop\n\n\n#line 4\
    \ \"math/formalpowerseries.cpp\"\n\ntemplate <typename T, typename Conv>\nstruct\
    \ FormalPowerSeries {\n  using Poly = vector<T>;\n  const Conv conv;\n  FormalPowerSeries(const\
    \ Conv& _conv) : conv(_conv) {}\n\n  Poly pre(const Poly& A, int deg) {\n    return\
    \ Poly(A.begin(), A.begin() + min((int)A.size(), deg));\n  }\n\n  Poly add(const\
    \ Poly& A, const Poly& B) {\n    int sz = max(A.size(), B.size());\n    Poly cs(sz,\
    \ T(0));\n    rep(i, A.size()) cs[i] += A[i];\n    rep(i, B.size()) cs[i] += B[i];\n\
    \    return cs;\n  }\n\n  Poly sub(const Poly& A, const Poly& B) {\n    int sz\
    \ = max(A.size(), B.size());\n    Poly cs(sz, T(0));\n    rep(i, A.size()) cs[i]\
    \ += A[i];\n    rep(i, B.size()) cs[i] -= B[i];\n    return cs;\n  }\n\n  Poly\
    \ mul(Poly& A, Poly& B) { return conv(A, B); }\n\n  Poly mul(const Poly& A, T\
    \ k) {\n    Poly res = A;\n    for (auto& a : res) a *= k;\n    return res;\n\
    \  }\n\n  // A[0] != 0\n  Poly inv(const Poly& A, int deg) {\n    assert(A[0]\
    \ != T(0));\n    Poly rs({T(1) / A[0]});\n    for (int i = 1; i < deg; i <<= 1)\n\
    \      rs = pre(sub(add(rs, rs), mul(mul(rs, rs), pre(A, i << 1))), i << 1);\n\
    \    return rs;\n  }\n\n  // nonzero\n  Poly div(const Poly& A, const Poly& B)\
    \ {\n    while (not A.empty() and A.back() == T(0)) A.pop_back();\n    while (B.back()\
    \ == T(0)) B.pop_back();\n    if (B.size() > A.size()) return Poly();\n    int\
    \ need = A.size() - B.size() + 1;\n    Poly ds = pre(mul(Poly(rall(A)), inv(Poly(rall(B)),\
    \ need)), need);\n    reverse(all(ds));\n    return ds;\n  }\n\n  Poly mod(const\
    \ Poly& A, const Poly& B) {\n    if (A == Poly(A.size(), 0)) return Poly({0});\n\
    \    Poly res = sub(A, mul(div(A, B), B));\n    while (not res.empty() and res.back()\
    \ == T(0)) res.pop_back();\n    return res;\n  }\n\n  // A[0] == 1\n  Poly sqrt(const\
    \ Poly& A, int deg) {\n    assert(A[0] == T(1));\n    T inv2 = T(1) / T(2);\n\
    \    Poly ss({T(1)});\n    for (int i = 1; i < deg; i <<= 1) {\n      ss = pre(add(ss,\
    \ mul(pre(A, i << 1), inv(ss, i << 1))), i << 1);\n      for (T& x : ss) x *=\
    \ inv2;\n    }\n    return ss;\n  }\n\n  Poly derivative(const Poly& A) {\n  \
    \  int n = A.size();\n    Poly rs(n - 1);\n    for (int i = 1; i < n; i++) rs[i\
    \ - 1] = A[i] * T(i);\n    return rs;\n  }\n\n  Poly integral(const Poly& A) {\n\
    \    static binomial<T> binom(0);\n    int n = A.size();\n    if (binom.invfact.size()\
    \ <= n)\n      binom = binomial<T>(1 << (32 - __builtin_clz(n) + 1));\n    Poly\
    \ rs(n + 1);\n    rs[0] = T(0);\n    for (int i = 0; i < n; i++) rs[i + 1] = A[i]\
    \ * binom.invfact[i + 1] * binom.fact[i];\n    return rs;\n  }\n\n  // A[0] ==\
    \ 1\n  Poly log(const Poly& A, int deg) {\n    assert(A[0] == 1)\n    return pre(integral(mul(derivative(A),\
    \ inv(A, deg))), deg);\n  }\n\n  // A[0] == 0\n  Poly exp(Poly A, int deg) {\n\
    \    assert(A[0] == 0);\n    Poly f({T(1)});\n    A[0] += T(1);\n    for (int\
    \ i = 1; i < deg; i <<= 1)\n      f = pre(mul(f, sub(pre(A, i << 1), log(f, i\
    \ << 1))), i << 1);\n    return f;\n  }\n};\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n\ntemplate <typename T, typename\
    \ Conv>\nstruct FormalPowerSeries {\n  using Poly = vector<T>;\n  const Conv conv;\n\
    \  FormalPowerSeries(const Conv& _conv) : conv(_conv) {}\n\n  Poly pre(const Poly&\
    \ A, int deg) {\n    return Poly(A.begin(), A.begin() + min((int)A.size(), deg));\n\
    \  }\n\n  Poly add(const Poly& A, const Poly& B) {\n    int sz = max(A.size(),\
    \ B.size());\n    Poly cs(sz, T(0));\n    rep(i, A.size()) cs[i] += A[i];\n  \
    \  rep(i, B.size()) cs[i] += B[i];\n    return cs;\n  }\n\n  Poly sub(const Poly&\
    \ A, const Poly& B) {\n    int sz = max(A.size(), B.size());\n    Poly cs(sz,\
    \ T(0));\n    rep(i, A.size()) cs[i] += A[i];\n    rep(i, B.size()) cs[i] -= B[i];\n\
    \    return cs;\n  }\n\n  Poly mul(Poly& A, Poly& B) { return conv(A, B); }\n\n\
    \  Poly mul(const Poly& A, T k) {\n    Poly res = A;\n    for (auto& a : res)\
    \ a *= k;\n    return res;\n  }\n\n  // A[0] != 0\n  Poly inv(const Poly& A, int\
    \ deg) {\n    assert(A[0] != T(0));\n    Poly rs({T(1) / A[0]});\n    for (int\
    \ i = 1; i < deg; i <<= 1)\n      rs = pre(sub(add(rs, rs), mul(mul(rs, rs), pre(A,\
    \ i << 1))), i << 1);\n    return rs;\n  }\n\n  // nonzero\n  Poly div(const Poly&\
    \ A, const Poly& B) {\n    while (not A.empty() and A.back() == T(0)) A.pop_back();\n\
    \    while (B.back() == T(0)) B.pop_back();\n    if (B.size() > A.size()) return\
    \ Poly();\n    int need = A.size() - B.size() + 1;\n    Poly ds = pre(mul(Poly(rall(A)),\
    \ inv(Poly(rall(B)), need)), need);\n    reverse(all(ds));\n    return ds;\n \
    \ }\n\n  Poly mod(const Poly& A, const Poly& B) {\n    if (A == Poly(A.size(),\
    \ 0)) return Poly({0});\n    Poly res = sub(A, mul(div(A, B), B));\n    while\
    \ (not res.empty() and res.back() == T(0)) res.pop_back();\n    return res;\n\
    \  }\n\n  // A[0] == 1\n  Poly sqrt(const Poly& A, int deg) {\n    assert(A[0]\
    \ == T(1));\n    T inv2 = T(1) / T(2);\n    Poly ss({T(1)});\n    for (int i =\
    \ 1; i < deg; i <<= 1) {\n      ss = pre(add(ss, mul(pre(A, i << 1), inv(ss, i\
    \ << 1))), i << 1);\n      for (T& x : ss) x *= inv2;\n    }\n    return ss;\n\
    \  }\n\n  Poly derivative(const Poly& A) {\n    int n = A.size();\n    Poly rs(n\
    \ - 1);\n    for (int i = 1; i < n; i++) rs[i - 1] = A[i] * T(i);\n    return\
    \ rs;\n  }\n\n  Poly integral(const Poly& A) {\n    static binomial<T> binom(0);\n\
    \    int n = A.size();\n    if (binom.invfact.size() <= n)\n      binom = binomial<T>(1\
    \ << (32 - __builtin_clz(n) + 1));\n    Poly rs(n + 1);\n    rs[0] = T(0);\n \
    \   for (int i = 0; i < n; i++) rs[i + 1] = A[i] * binom.invfact[i + 1] * binom.fact[i];\n\
    \    return rs;\n  }\n\n  // A[0] == 1\n  Poly log(const Poly& A, int deg) {\n\
    \    assert(A[0] == 1)\n    return pre(integral(mul(derivative(A), inv(A, deg))),\
    \ deg);\n  }\n\n  // A[0] == 0\n  Poly exp(Poly A, int deg) {\n    assert(A[0]\
    \ == 0);\n    Poly f({T(1)});\n    A[0] += T(1);\n    for (int i = 1; i < deg;\
    \ i <<= 1)\n      f = pre(mul(f, sub(pre(A, i << 1), log(f, i << 1))), i << 1);\n\
    \    return f;\n  }\n};\n"
  dependsOn:
  - template.cpp
  isVerificationFile: false
  path: math/formalpowerseries.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/formalpowerseries.cpp
layout: document
redirect_from:
- /library/math/formalpowerseries.cpp
- /library/math/formalpowerseries.cpp.html
title: math/formalpowerseries.cpp
---
