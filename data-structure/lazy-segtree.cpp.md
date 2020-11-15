---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: util/function-objects.cpp
    title: util/function-objects.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/hash-monoid.cpp
    title: string/hash-monoid.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/0355.test.cpp
    title: verify/aoj/0355.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/lazy-segtree.cpp\"\n\n#line 2 \"template.cpp\"\
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
    \ \"util/function-objects.cpp\"\n\n#line 4 \"util/function-objects.cpp\"\n\nstruct\
    \ minT {\n  template <typename T>\n  T operator()(T a, T b) const {\n    return\
    \ min(a, b);\n  }\n};\n\nstruct maxT {\n  template <typename T>\n  T operator()(T\
    \ a, T b) const {\n    return max(a, b);\n  }\n};\n\n#pragma GCC diagnostic push\n\
    #pragma GCC diagnostic ignored \"-Wunused-parameter\"\nstruct assignT {\n  template\
    \ <typename T>\n  T operator()(T a, T b, int k = 0) const { return b; }\n};\n\
    #pragma GCC diagnostic pop\n\nstruct plusT {\n  template <typename T>\n  T operator()(T\
    \ a, T b, int k = 1) const { return a + b * k; }\n};\n#line 5 \"data-structure/lazy-segtree.cpp\"\
    \n\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wshadow\"\n\
    template <typename T, typename Actor, typename Combine, typename ACombine,\n \
    \         typename Action>\nstruct LazySegmentTree {\n private:\n  const size_t\
    \ n, h;\n  const T unit;\n  const Actor aunit;\n  const Combine combine;\n  const\
    \ ACombine acombine;\n  const Action upd;\n  vector<T> data;\n  vector<Actor>\
    \ lazy;\n\n public:\n  LazySegmentTree(size_t n = 0, T unit = {}, Actor aunit\
    \ = {},\n                  Combine combine = {}, ACombine acombine = {}, Action\
    \ upd = {})\n      : n(n),\n        h(32 - __builtin_clz(n)),\n        unit(unit),\n\
    \        aunit(aunit),\n        combine(combine),\n        acombine(acombine),\n\
    \        upd(upd),\n        data(n << 1, unit),\n        lazy(n, aunit) {\n  \
    \  build(0, n);\n  }\n\n  template <\n      typename Iter,\n      enable_if_t<is_same<typename\
    \ Iter::value_type, T>::value>* = nullptr>\n  LazySegmentTree(Iter first, Iter\
    \ last, size_t n, T unit = {},\n                  Actor aunit = {}, Combine combine\
    \ = {},\n                  ACombine acombine = {}, Action upd = {})\n      : n(n),\n\
    \        h(32 - __builtin_clz(n)),\n        unit(unit),\n        aunit(aunit),\n\
    \        combine(combine),\n        acombine(acombine),\n        upd(upd),\n \
    \       data(n << 1, unit),\n        lazy(n, aunit) {\n    copy(first, last, data.begin()\
    \ + n);\n    build(0, n);\n  }\n\n  template <\n      typename Iter,\n      enable_if_t<!is_same<typename\
    \ Iter::value_type, T>::value>* = nullptr>\n  [[deprecated]] LazySegmentTree(Iter\
    \ first, Iter last, size_t n, T unit = {},\n                                 Actor\
    \ aunit = {}, Combine combine = {},\n                                 ACombine\
    \ acombine = {}, Action upd = {})\n      : n(n),\n        h(32 - __builtin_clz(n)),\n\
    \        unit(unit),\n        aunit(aunit),\n        combine(combine),\n     \
    \   acombine(acombine),\n        upd(upd),\n        data(n << 1, unit),\n    \
    \    lazy(n, aunit) {\n    copy(first, last, data.begin() + n);\n    build(0,\
    \ n);\n  }\n\n  template <typename Iter>\n  LazySegmentTree(Iter first, Iter last,\
    \ T unit = {}, Actor aunit = {},\n                  Combine combine = {}, ACombine\
    \ acombine = {}, Action upd = {})\n      : LazySegmentTree(first, last, distance(first,\
    \ last), unit, aunit,\n                        combine, acombine, upd) {}\n\n\
    \ private:\n  void apply(int p, Actor e, int sz) {\n    if (e == aunit) return;\n\
    \    data[p] = upd(data[p], e, sz);\n    if (p < n) {\n      if (lazy[p] == aunit)\n\
    \        lazy[p] = e;\n      else\n        lazy[p] = acombine(lazy[p], e);\n \
    \   }\n  }\n\n  void pushdown(int p, int sz) {\n    if (p >= n or lazy[p] == aunit)\
    \ return;\n    apply(p << 1, lazy[p], sz >> 1);\n    apply(p << 1 | 1, lazy[p],\
    \ sz >> 1);\n    lazy[p] = aunit;\n  }\n\n  void pushup(int p, int sz) {\n   \
    \ if (p >= n) return;\n    data[p] = combine(data[p << 1], data[p << 1 | 1]);\n\
    \    if (lazy[p] != aunit) data[p] = upd(data[p], lazy[p], sz);\n  }\n\n  void\
    \ flush(int l, int r) {\n    int s = h, k = 1 << h;\n    for (l += n, r += n -\
    \ 1; s > 0; s--, k >>= 1)\n      for (int p = l >> s; p <= r >> s; p++) pushdown(p,\
    \ k);\n  }\n\n  void build(int l, int r) {\n    int sz = 2;\n    for (l += n,\
    \ r += n - 1; l > 1; sz <<= 1) {\n      l >>= 1, r >>= 1;\n      for (int p =\
    \ l; p <= r; p++) pushup(p, sz);\n    }\n  }\n\n public:\n  void modify(int l,\
    \ int r, Actor e) {\n    if (e == aunit) return;\n    flush(l, l + 1);\n    flush(r\
    \ - 1, r);\n    int l0 = l, r0 = r, k = 1;\n    for (l += n, r += n; l < r; l\
    \ >>= 1, r >>= 1, k <<= 1) {\n      if (l & 1) apply(l++, e, k);\n      if (r\
    \ & 1) apply(--r, e, k);\n    }\n    build(l0, l0 + 1);\n    build(r0 - 1, r0);\n\
    \  }\n\n  T fold(int l, int r) {\n    flush(l, l + 1);\n    flush(r - 1, r);\n\
    \    T resl = unit, resr = unit;\n    for (l += n, r += n; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) resl = combine(resl, data[l++]);\n      if (r & 1) resr\
    \ = combine(data[--r], resr);\n    }\n    return combine(resl, resr);\n  }\n};\n\
    #pragma GCC diagnostic pop\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"util/function-objects.cpp\"\
    \n\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wshadow\"\n\
    template <typename T, typename Actor, typename Combine, typename ACombine,\n \
    \         typename Action>\nstruct LazySegmentTree {\n private:\n  const size_t\
    \ n, h;\n  const T unit;\n  const Actor aunit;\n  const Combine combine;\n  const\
    \ ACombine acombine;\n  const Action upd;\n  vector<T> data;\n  vector<Actor>\
    \ lazy;\n\n public:\n  LazySegmentTree(size_t n = 0, T unit = {}, Actor aunit\
    \ = {},\n                  Combine combine = {}, ACombine acombine = {}, Action\
    \ upd = {})\n      : n(n),\n        h(32 - __builtin_clz(n)),\n        unit(unit),\n\
    \        aunit(aunit),\n        combine(combine),\n        acombine(acombine),\n\
    \        upd(upd),\n        data(n << 1, unit),\n        lazy(n, aunit) {\n  \
    \  build(0, n);\n  }\n\n  template <\n      typename Iter,\n      enable_if_t<is_same<typename\
    \ Iter::value_type, T>::value>* = nullptr>\n  LazySegmentTree(Iter first, Iter\
    \ last, size_t n, T unit = {},\n                  Actor aunit = {}, Combine combine\
    \ = {},\n                  ACombine acombine = {}, Action upd = {})\n      : n(n),\n\
    \        h(32 - __builtin_clz(n)),\n        unit(unit),\n        aunit(aunit),\n\
    \        combine(combine),\n        acombine(acombine),\n        upd(upd),\n \
    \       data(n << 1, unit),\n        lazy(n, aunit) {\n    copy(first, last, data.begin()\
    \ + n);\n    build(0, n);\n  }\n\n  template <\n      typename Iter,\n      enable_if_t<!is_same<typename\
    \ Iter::value_type, T>::value>* = nullptr>\n  [[deprecated]] LazySegmentTree(Iter\
    \ first, Iter last, size_t n, T unit = {},\n                                 Actor\
    \ aunit = {}, Combine combine = {},\n                                 ACombine\
    \ acombine = {}, Action upd = {})\n      : n(n),\n        h(32 - __builtin_clz(n)),\n\
    \        unit(unit),\n        aunit(aunit),\n        combine(combine),\n     \
    \   acombine(acombine),\n        upd(upd),\n        data(n << 1, unit),\n    \
    \    lazy(n, aunit) {\n    copy(first, last, data.begin() + n);\n    build(0,\
    \ n);\n  }\n\n  template <typename Iter>\n  LazySegmentTree(Iter first, Iter last,\
    \ T unit = {}, Actor aunit = {},\n                  Combine combine = {}, ACombine\
    \ acombine = {}, Action upd = {})\n      : LazySegmentTree(first, last, distance(first,\
    \ last), unit, aunit,\n                        combine, acombine, upd) {}\n\n\
    \ private:\n  void apply(int p, Actor e, int sz) {\n    if (e == aunit) return;\n\
    \    data[p] = upd(data[p], e, sz);\n    if (p < n) {\n      if (lazy[p] == aunit)\n\
    \        lazy[p] = e;\n      else\n        lazy[p] = acombine(lazy[p], e);\n \
    \   }\n  }\n\n  void pushdown(int p, int sz) {\n    if (p >= n or lazy[p] == aunit)\
    \ return;\n    apply(p << 1, lazy[p], sz >> 1);\n    apply(p << 1 | 1, lazy[p],\
    \ sz >> 1);\n    lazy[p] = aunit;\n  }\n\n  void pushup(int p, int sz) {\n   \
    \ if (p >= n) return;\n    data[p] = combine(data[p << 1], data[p << 1 | 1]);\n\
    \    if (lazy[p] != aunit) data[p] = upd(data[p], lazy[p], sz);\n  }\n\n  void\
    \ flush(int l, int r) {\n    int s = h, k = 1 << h;\n    for (l += n, r += n -\
    \ 1; s > 0; s--, k >>= 1)\n      for (int p = l >> s; p <= r >> s; p++) pushdown(p,\
    \ k);\n  }\n\n  void build(int l, int r) {\n    int sz = 2;\n    for (l += n,\
    \ r += n - 1; l > 1; sz <<= 1) {\n      l >>= 1, r >>= 1;\n      for (int p =\
    \ l; p <= r; p++) pushup(p, sz);\n    }\n  }\n\n public:\n  void modify(int l,\
    \ int r, Actor e) {\n    if (e == aunit) return;\n    flush(l, l + 1);\n    flush(r\
    \ - 1, r);\n    int l0 = l, r0 = r, k = 1;\n    for (l += n, r += n; l < r; l\
    \ >>= 1, r >>= 1, k <<= 1) {\n      if (l & 1) apply(l++, e, k);\n      if (r\
    \ & 1) apply(--r, e, k);\n    }\n    build(l0, l0 + 1);\n    build(r0 - 1, r0);\n\
    \  }\n\n  T fold(int l, int r) {\n    flush(l, l + 1);\n    flush(r - 1, r);\n\
    \    T resl = unit, resr = unit;\n    for (l += n, r += n; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) resl = combine(resl, data[l++]);\n      if (r & 1) resr\
    \ = combine(data[--r], resr);\n    }\n    return combine(resl, resr);\n  }\n};\n\
    #pragma GCC diagnostic pop\n"
  dependsOn:
  - template.cpp
  - util/function-objects.cpp
  isVerificationFile: false
  path: data-structure/lazy-segtree.cpp
  requiredBy:
  - string/hash-monoid.cpp
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/0355.test.cpp
documentation_of: data-structure/lazy-segtree.cpp
layout: document
redirect_from:
- /library/data-structure/lazy-segtree.cpp
- /library/data-structure/lazy-segtree.cpp.html
title: data-structure/lazy-segtree.cpp
---
