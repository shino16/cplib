---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segtree.cpp
    title: data-structure/lazy-segtree.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.cpp
    title: data-structure/segtree.cpp
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.cpp
    title: string/rolling-hash.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':heavy_check_mark:'
    path: util/function-objects.cpp
    title: util/function-objects.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/0355.test.cpp
    title: verify/aoj/0355.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/hash-monoid.cpp\"\n\n#line 2 \"string/rolling-hash.cpp\"\
    \n\n#include <random>\n#line 2 \"template.cpp\"\n\n#ifndef LOCAL\n#pragma GCC\
    \ optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#pragma GCC target(\"\
    avx\")\n#endif\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n\
    #include <cmath>\n#include <functional>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\nusing\
    \ namespace std;\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ VI = vector<int>;\nusing VVI = vector<vector<int>>;\nusing VLL = vector<ll>;\n\
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
    #else\n#define dump(...) ({})\n#endif\n#pragma GCC diagnostic pop\n\n\n#line 5\
    \ \"string/rolling-hash.cpp\"\n\nnamespace rolling_hash {\n\nconstexpr ull mask30\
    \ = (1ULL << 30) - 1;\nconstexpr ull mask31 = (1ULL << 31) - 1;\nconstexpr ull\
    \ MOD = (1ULL << 61) - 1;\nrandom_device rd;\nint base = uniform_int_distribution<int>(0)(rd);\n\
    vector<ull> pows{1};\nvector<ull> sum_pows{1};\n\null mod(ull val) {\n  val =\
    \ (val & MOD) + (val >> 61);\n  return val >= MOD ? val - MOD : val;\n}\n\null\
    \ mul(ull l, ull r) {\n  ull lu = l >> 31, ld = l & mask31;\n  ull ru = r >> 31,\
    \ rd = r & mask31;\n  ull middle = ld * ru + lu * rd;\n  return ((lu * ru) <<\
    \ 1) + ld * rd + ((middle & mask30) << 31) +\n         (middle >> 30);\n}\n\n\
    ull mul(ull l, int r) {\n  ull lu = l >> 31, ld = l & mask31;\n  ull middle =\
    \ lu * r;\n  return ld * r + ((middle & mask30) << 31) + (middle >> 30);\n}\n\n\
    void prepare_pows(size_t sz) {\n  rep(i, pows.size() - 1, sz - 1) pows.push_back(mod(mul(pows[i],\
    \ base)));\n}\n\nvoid prepare_sum_pows(size_t sz) {\n  prepare_pows(sz);\n  rep(i,\
    \ sum_pows.size() - 1, sz - 1) {\n    sum_pows.push_back(mod(sum_pows[i] + pows[i\
    \ + 1]));\n  }\n}\n\null calc_hash(char c, int _length) {\n  prepare_sum_pows(_length);\n\
    \  return mod(mul(sum_pows[_length - 1], c));\n}\n\ntemplate <typename Iter>\n\
    ull calc_hash(Iter first, Iter last) {\n  ull res = 0;\n  while (first != last)\
    \ res = mod(mul(res, base) + *first++);\n  return res;\n}\n\n// monoid\nstruct\
    \ Hash {\n  ull value;\n  int length;\n\n  Hash() : value(0), length(0) {}  //\
    \ unit\n  Hash(ull _value, int _length) : value(_value), length(_length) {}\n\
    \  Hash(char c, int _length = 1)\n      : value(calc_hash(c, _length)), length(_length)\
    \ {}\n  template <typename Iter>\n  Hash(Iter first, Iter last): value(calc_hash(first,\
    \ last)), length(distance(first, last)) {}\n\n public:\n  operator ull() const\
    \ { return value; }\n  bool operator==(const Hash& rhs) const {\n    return value\
    \ == rhs.value && length == rhs.length;\n  }\n  bool operator!=(const Hash& rhs)\
    \ const {\n    return value != rhs.value && length != rhs.length;\n  }\n  bool\
    \ operator<(const Hash& rhs) const {\n    return make_pair(length, value) < make_pair(rhs.length,\
    \ rhs.value);\n  }\n};\n\nclass Calculator {\n private:\n  vector<ull> hash;\n\
    \n public:\n  template <typename Iter>\n  Calculator(Iter first, Iter last) :\
    \ hash(last - first + 1) {\n    prepare_pows(last - first + 1);\n    rep(i, last\
    \ - first) hash[i + 1] = mod(mul(hash[i], base) + first[i]);\n    // assert(hash[i+1]\
    \ < (1ULL << 62));\n  }\n\n public:\n  ull operator()(int l, int r) const {\n\
    \    static constexpr ull large = MOD * ((1 << 2) - 1);\n    return mod(hash[r]\
    \ + large - mul(hash[l], pows[r - l]));\n  }\n  Hash get_hash(int l, int r) const\
    \ {\n    return Hash(operator()(l, r), r - l);\n  }\n};\n\n}  // namespace rolling_hash\n\
    #line 2 \"data-structure/segtree.cpp\"\n\n#line 2 \"util/function-objects.cpp\"\
    \n\n#line 4 \"util/function-objects.cpp\"\n\nstruct minT {\n  template <typename\
    \ T>\n  T operator()(T a, T b) const {\n    return min(a, b);\n  }\n};\n\nstruct\
    \ maxT {\n  template <typename T>\n  T operator()(T a, T b) const {\n    return\
    \ max(a, b);\n  }\n};\n\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored\
    \ \"-Wunused-parameter\"\nstruct assignT {\n  template <typename T>\n  T operator()(T\
    \ a, T b, int k = 0) const { return b; }\n};\n#pragma GCC diagnostic pop\n\nstruct\
    \ plusT {\n  template <typename T>\n  T operator()(T a, T b, int k = 1) const\
    \ { return a + b * k; }\n};\n#line 5 \"data-structure/segtree.cpp\"\n\n#pragma\
    \ GCC diagnostic push\n#pragma GCC diagnostic ignored \"-Wshadow\"\ntemplate <typename\
    \ T, typename Combine, typename Action>\nclass SegmentTree {\n private:\n  const\
    \ size_t n;\n  const T unit;\n  const Combine combine;\n  const Action action;\n\
    \  vector<T> data;\n\n public:\n  SegmentTree(size_t n = 0, T unit = {}, Combine\
    \ combine = {},\n              Action action = {})\n      : n(n), unit(unit),\
    \ combine(combine), action(action), data(n << 1, unit) {\n    build();\n  }\n\n\
    \  template <\n      typename Iter,\n      enable_if_t<is_same<typename Iter::value_type,\
    \ T>::value>* = nullptr>\n  SegmentTree(Iter first, Iter last, size_t n, T unit\
    \ = {},\n              Combine combine = {}, Action action = {})\n      : n(n),\
    \ unit(unit), combine(combine), action(action), data(n << 1) {\n    copy(first,\
    \ last, data.begin() + n);\n    build();\n  }\n\n  template <\n      typename\
    \ Iter,\n      enable_if_t<!is_same<typename Iter::value_type, T>::value>* = nullptr>\n\
    \  [[deprecated]] SegmentTree(Iter first, Iter last, size_t n, T unit = {},\n\
    \                             Combine combine = {}, Action action = {})\n    \
    \  : n(n), unit(unit), combine(combine), action(action), data(n << 1) {\n    copy(first,\
    \ last, data.begin() + n);\n    build();\n  }\n\n  template <typename Iter>\n\
    \  SegmentTree(Iter first, Iter last, T unit = {}, Combine combine = {},\n   \
    \           Action action = {})\n      : SegmentTree(first, last, distance(first,\
    \ last), unit, combine, action) {\n  }\n\n private:\n  void build() { repr(i,\
    \ n) data[i] = combine(data[i << 1], data[i << 1 | 1]); }\n\n public:\n  void\
    \ modify(int l, T v) {\n    l += n;\n    data[l] = action(data[l], v);\n    for\
    \ (; l > 1; l >>= 1) data[l >> 1] = combine(data[l & (~1)], data[l | 1]);\n  }\n\
    \n  T fold(int l, int r) const {\n    if (l == r) return unit;\n    if (l + 1\
    \ == r) return data[l + n];\n    T resl = data[l += n], resr = data[(r += n) -\
    \ 1];\n    for (l++, r--; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) resl =\
    \ combine(resl, data[l++]);\n      if (r & 1) resr = combine(data[--r], resr);\n\
    \    }\n    return combine(resl, resr);\n  }\n  // min r s.t. fold(l, r) >= v\
    \ -- or n+1 if failed\n  template <typename Compare = less<T>>\n  int lower_bound(T\
    \ v, int l = 0, Compare comp = {}) {\n    if (not comp(unit, v)) return l;\n \
    \   int r = n;\n    VI rootL, rootR;\n    for (l += n, r += n; l < r; l >>= 1,\
    \ r >>= 1) {\n      if (l & 1) rootL.push_back(l++);\n      if (r & 1) rootR.push_back(--r);\n\
    \    }\n    VI roots = move(rootL); roots.insert(roots.end(), rall(rootR));\n\
    \    T accL = unit;\n    for (int root : roots) {\n      T tmpL = combine(accL,\
    \ data[root]);\n      if (comp(tmpL, v)) {\n        accL = tmpL;\n        continue;\n\
    \      }\n      while (root < n) {\n        tmpL = combine(accL, data[root <<\
    \ 1]);\n        if (comp(tmpL, v)) accL = tmpL, root = root << 1 | 1;\n      \
    \  else root = root << 1;\n      }\n      return root - n + 1;\n    }\n    return\
    \ n + 1;\n  }\n};\n#pragma GCC diagnostic pop\n#line 2 \"data-structure/lazy-segtree.cpp\"\
    \n\n#line 5 \"data-structure/lazy-segtree.cpp\"\n\n#pragma GCC diagnostic push\n\
    #pragma GCC diagnostic ignored \"-Wshadow\"\ntemplate <typename T, typename Actor,\
    \ typename Combine, typename ACombine,\n          typename Action>\nstruct LazySegmentTree\
    \ {\n private:\n  const size_t n, h;\n  const T unit;\n  const Actor aunit;\n\
    \  const Combine combine;\n  const ACombine acombine;\n  const Action upd;\n \
    \ vector<T> data;\n  vector<Actor> lazy;\n\n public:\n  LazySegmentTree(size_t\
    \ n = 0, T unit = {}, Actor aunit = {},\n                  Combine combine = {},\
    \ ACombine acombine = {}, Action upd = {})\n      : n(n),\n        h(32 - __builtin_clz(n)),\n\
    \        unit(unit),\n        aunit(aunit),\n        combine(combine),\n     \
    \   acombine(acombine),\n        upd(upd),\n        data(n << 1, unit),\n    \
    \    lazy(n, aunit) {\n    build(0, n);\n  }\n\n  template <\n      typename Iter,\n\
    \      enable_if_t<is_same<typename Iter::value_type, T>::value>* = nullptr>\n\
    \  LazySegmentTree(Iter first, Iter last, size_t n, T unit = {},\n           \
    \       Actor aunit = {}, Combine combine = {},\n                  ACombine acombine\
    \ = {}, Action upd = {})\n      : n(n),\n        h(32 - __builtin_clz(n)),\n \
    \       unit(unit),\n        aunit(aunit),\n        combine(combine),\n      \
    \  acombine(acombine),\n        upd(upd),\n        data(n << 1, unit),\n     \
    \   lazy(n, aunit) {\n    copy(first, last, data.begin() + n);\n    build(0, n);\n\
    \  }\n\n  template <\n      typename Iter,\n      enable_if_t<!is_same<typename\
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
    #pragma GCC diagnostic pop\n#line 6 \"string/hash-monoid.cpp\"\n\nnamespace hash_monoid\
    \ {\n\nusing namespace rolling_hash;\n\nstruct mergeT {\n  Hash operator()(const\
    \ Hash& lhs, const Hash& rhs) const {\n    prepare_pows(rhs.length + 1);\n   \
    \ return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),\n           \
    \     lhs.length + rhs.length);\n  }\n};\n\n#pragma GCC diagnostic push\n#pragma\
    \ GCC diagnostic ignored \"-Wunused-parameter\"\nstruct updT {\n  Hash operator()(const\
    \ Hash& lhs, char c, int k = 1) const {\n    return Hash(c, k);\n  }\n};\n#pragma\
    \ GCC diagnostic pop\n\n}  // namespace hash_monoid\n\nusing HashSegTree =\n \
    \   SegmentTree<rolling_hash::Hash, hash_monoid::mergeT, hash_monoid::updT>;\n\
    using LazyHashSegTree =\n    LazySegmentTree<rolling_hash::Hash, char, hash_monoid::mergeT,\
    \ assignT,\n                    hash_monoid::updT>;\n"
  code: "#pragma once\n\n#include \"string/rolling-hash.cpp\"\n#include \"data-structure/segtree.cpp\"\
    \n#include \"data-structure/lazy-segtree.cpp\"\n\nnamespace hash_monoid {\n\n\
    using namespace rolling_hash;\n\nstruct mergeT {\n  Hash operator()(const Hash&\
    \ lhs, const Hash& rhs) const {\n    prepare_pows(rhs.length + 1);\n    return\
    \ Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),\n                lhs.length\
    \ + rhs.length);\n  }\n};\n\n#pragma GCC diagnostic push\n#pragma GCC diagnostic\
    \ ignored \"-Wunused-parameter\"\nstruct updT {\n  Hash operator()(const Hash&\
    \ lhs, char c, int k = 1) const {\n    return Hash(c, k);\n  }\n};\n#pragma GCC\
    \ diagnostic pop\n\n}  // namespace hash_monoid\n\nusing HashSegTree =\n    SegmentTree<rolling_hash::Hash,\
    \ hash_monoid::mergeT, hash_monoid::updT>;\nusing LazyHashSegTree =\n    LazySegmentTree<rolling_hash::Hash,\
    \ char, hash_monoid::mergeT, assignT,\n                    hash_monoid::updT>;\n"
  dependsOn:
  - string/rolling-hash.cpp
  - template.cpp
  - data-structure/segtree.cpp
  - util/function-objects.cpp
  - data-structure/lazy-segtree.cpp
  isVerificationFile: false
  path: string/hash-monoid.cpp
  requiredBy: []
  timestamp: '2020-05-27 03:32:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/0355.test.cpp
documentation_of: string/hash-monoid.cpp
layout: document
redirect_from:
- /library/string/hash-monoid.cpp
- /library/string/hash-monoid.cpp.html
title: string/hash-monoid.cpp
---
