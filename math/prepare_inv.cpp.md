---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/modint.cpp
    title: math/modint.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prepare_inv.cpp\"\n\n#line 2 \"template.cpp\"\n\n#ifndef\
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
    \ \"math/modint.cpp\"\n\n#line 4 \"math/modint.cpp\"\n\ntemplate <ll> class modint;\n\
    template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);\n\ntemplate <ll\
    \ MOD = 1000000007>\nclass modint {\npublic:\n  ll value;\n  static constexpr\
    \ ll Mod = MOD;\n\n  constexpr modint(const ll x = 0) noexcept : value(x) {\n\
    \    value %= MOD;\n    if (value < 0) value += MOD;\n  }\n  constexpr bool operator==(const\
    \ modint& rhs) {\n    return value == rhs.value;\n  }\n  constexpr bool operator!=(const\
    \ modint& rhs) {\n    return value != rhs.value;\n  }\n  constexpr modint operator-()\
    \ const {\n    return modint(0) - *this;\n  }\n  constexpr modint operator+(const\
    \ modint& rhs) const {\n    return modint(*this) += rhs;\n  }\n  constexpr modint\
    \ operator-(const modint& rhs) const {\n    return modint(*this) -= rhs;\n  }\n\
    \  constexpr modint operator*(const modint& rhs) const {\n    return modint(*this)\
    \ *= rhs;\n  }\n  constexpr modint operator/(const modint& rhs) const {\n    return\
    \ modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const modint& rhs)\
    \ {\n    value += rhs.value;\n    if (value >= MOD) value -= MOD;\n    return\
    \ *this;\n  }\n  constexpr modint& operator-=(const modint& rhs) {\n    if (value\
    \ < rhs.value) value += MOD;\n    value -= rhs.value;\n    return *this;\n  }\n\
    \  constexpr modint& operator*=(const modint& rhs) {\n    value = value * rhs.value\
    \ % MOD;\n    return *this;\n  }\n  constexpr modint& operator/=(const modint&\
    \ rhs) {\n    return *this *= pow(rhs, MOD - 2);\n  }\n  constexpr modint& operator++()\
    \ {\n    return *this += 1;\n  }\n  constexpr modint operator++(int) {\n    modint\
    \ tmp(*this);\n    ++(*this);\n    return tmp;\n  }\n  constexpr modint& operator--()\
    \ {\n    return *this -= 1;\n  }\n  constexpr modint operator--(int) {\n    modint\
    \ tmp(*this);\n    --(*this);\n    return tmp;\n  }\n  constexpr operator int()\
    \ const {\n    return (int)value;\n  }\n  constexpr operator ll() const {\n  \
    \  return value;\n  }\n};\n\n\ntemplate <typename OutStream, ll MOD>\nOutStream&\
    \ operator<<(OutStream& out, modint<MOD> n) {\n  out << n.value;\n  return out;\n\
    }\n\ntemplate <typename InStream, ll MOD>\nInStream& operator>>(InStream& in,\
    \ modint<MOD>& n) {\n  ll var; in >> var; n = modint<MOD>(var);\n  return in;\n\
    }\n\ntemplate <ll MOD>\nconstexpr modint<MOD> pow(modint<MOD> base, ll exp) {\n\
    \  modint<MOD> res = 1;\n  while (exp) {\n    if (exp % 2) res *= base;\n    base\
    \ *= base;\n    exp /= 2;\n  }\n  return res;\n}\n\n// O(r + log MOD)\ntemplate\
    \ <ll MOD>\nmodint<MOD> choose(int n, int r) {\n  chmin(r, n-r);\n  if (r < 0)\
    \ return modint<MOD>(0);\n  modint<MOD> nu = 1, de = 1;\n  rep(i, r) nu *= n-i,\
    \ de *= i+1;\n  return nu / de;\n}\n#line 5 \"math/prepare_inv.cpp\"\n\ntemplate\
    \ <ll Mod>\nvector<modint<Mod>> prepare_inv(int n) {\n  n++;\n  vector<modint<Mod>>\
    \ res(n);\n  res[1] = modint<Mod>(1);\n  rep(i, 2, n) res[i] = -res[Mod % i] *\
    \ modint<Mod>(Mod / i);\n  return res;\n}\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"math/modint.cpp\"\n\
    \ntemplate <ll Mod>\nvector<modint<Mod>> prepare_inv(int n) {\n  n++;\n  vector<modint<Mod>>\
    \ res(n);\n  res[1] = modint<Mod>(1);\n  rep(i, 2, n) res[i] = -res[Mod % i] *\
    \ modint<Mod>(Mod / i);\n  return res;\n}\n"
  dependsOn:
  - template.cpp
  - math/modint.cpp
  isVerificationFile: false
  path: math/prepare_inv.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prepare_inv.cpp
layout: document
redirect_from:
- /library/math/prepare_inv.cpp
- /library/math/prepare_inv.cpp.html
title: math/prepare_inv.cpp
---
