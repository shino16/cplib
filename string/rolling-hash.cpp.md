---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
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
  bundledCode: "#line 2 \"string/rolling-hash.cpp\"\n\n#include <random>\n#line 2\
    \ \"template.cpp\"\n\n#ifndef LOCAL\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#pragma GCC target(\"avx\")\n#endif\n#include <algorithm>\n\
    #include <bitset>\n#include <cassert>\n#include <cmath>\n#include <functional>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing VI = vector<int>;\nusing VVI = vector<vector<int>>;\n\
    using VLL = vector<ll>;\nusing VVLL = vector<vector<ll>>;\nusing VB = vector<bool>;\n\
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
    \ {\n    return Hash(operator()(l, r), r - l);\n  }\n};\n\n}  // namespace rolling_hash\n"
  code: "#pragma once\n\n#include <random>\n#include \"template.cpp\"\n\nnamespace\
    \ rolling_hash {\n\nconstexpr ull mask30 = (1ULL << 30) - 1;\nconstexpr ull mask31\
    \ = (1ULL << 31) - 1;\nconstexpr ull MOD = (1ULL << 61) - 1;\nrandom_device rd;\n\
    int base = uniform_int_distribution<int>(0)(rd);\nvector<ull> pows{1};\nvector<ull>\
    \ sum_pows{1};\n\null mod(ull val) {\n  val = (val & MOD) + (val >> 61);\n  return\
    \ val >= MOD ? val - MOD : val;\n}\n\null mul(ull l, ull r) {\n  ull lu = l >>\
    \ 31, ld = l & mask31;\n  ull ru = r >> 31, rd = r & mask31;\n  ull middle = ld\
    \ * ru + lu * rd;\n  return ((lu * ru) << 1) + ld * rd + ((middle & mask30) <<\
    \ 31) +\n         (middle >> 30);\n}\n\null mul(ull l, int r) {\n  ull lu = l\
    \ >> 31, ld = l & mask31;\n  ull middle = lu * r;\n  return ld * r + ((middle\
    \ & mask30) << 31) + (middle >> 30);\n}\n\nvoid prepare_pows(size_t sz) {\n  rep(i,\
    \ pows.size() - 1, sz - 1) pows.push_back(mod(mul(pows[i], base)));\n}\n\nvoid\
    \ prepare_sum_pows(size_t sz) {\n  prepare_pows(sz);\n  rep(i, sum_pows.size()\
    \ - 1, sz - 1) {\n    sum_pows.push_back(mod(sum_pows[i] + pows[i + 1]));\n  }\n\
    }\n\null calc_hash(char c, int _length) {\n  prepare_sum_pows(_length);\n  return\
    \ mod(mul(sum_pows[_length - 1], c));\n}\n\ntemplate <typename Iter>\null calc_hash(Iter\
    \ first, Iter last) {\n  ull res = 0;\n  while (first != last) res = mod(mul(res,\
    \ base) + *first++);\n  return res;\n}\n\n// monoid\nstruct Hash {\n  ull value;\n\
    \  int length;\n\n  Hash() : value(0), length(0) {}  // unit\n  Hash(ull _value,\
    \ int _length) : value(_value), length(_length) {}\n  Hash(char c, int _length\
    \ = 1)\n      : value(calc_hash(c, _length)), length(_length) {}\n  template <typename\
    \ Iter>\n  Hash(Iter first, Iter last): value(calc_hash(first, last)), length(distance(first,\
    \ last)) {}\n\n public:\n  operator ull() const { return value; }\n  bool operator==(const\
    \ Hash& rhs) const {\n    return value == rhs.value && length == rhs.length;\n\
    \  }\n  bool operator!=(const Hash& rhs) const {\n    return value != rhs.value\
    \ && length != rhs.length;\n  }\n  bool operator<(const Hash& rhs) const {\n \
    \   return make_pair(length, value) < make_pair(rhs.length, rhs.value);\n  }\n\
    };\n\nclass Calculator {\n private:\n  vector<ull> hash;\n\n public:\n  template\
    \ <typename Iter>\n  Calculator(Iter first, Iter last) : hash(last - first + 1)\
    \ {\n    prepare_pows(last - first + 1);\n    rep(i, last - first) hash[i + 1]\
    \ = mod(mul(hash[i], base) + first[i]);\n    // assert(hash[i+1] < (1ULL << 62));\n\
    \  }\n\n public:\n  ull operator()(int l, int r) const {\n    static constexpr\
    \ ull large = MOD * ((1 << 2) - 1);\n    return mod(hash[r] + large - mul(hash[l],\
    \ pows[r - l]));\n  }\n  Hash get_hash(int l, int r) const {\n    return Hash(operator()(l,\
    \ r), r - l);\n  }\n};\n\n}  // namespace rolling_hash\n"
  dependsOn:
  - template.cpp
  isVerificationFile: false
  path: string/rolling-hash.cpp
  requiredBy:
  - string/hash-monoid.cpp
  timestamp: '2020-05-27 03:32:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/0355.test.cpp
documentation_of: string/rolling-hash.cpp
layout: document
redirect_from:
- /library/string/rolling-hash.cpp
- /library/string/rolling-hash.cpp.html
title: string/rolling-hash.cpp
---
