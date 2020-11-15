---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':warning:'
    path: util/doubling.cpp
    title: util/doubling.cpp
  - icon: ':warning:'
    path: util/mapping.cpp
    title: util/mapping.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/squarematrix.cpp\"\n\n#line 2 \"template.cpp\"\n\n\
    #ifndef LOCAL\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
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
    \ \"util/doubling.cpp\"\n\n#line 2 \"util/mapping.cpp\"\n\n#line 4 \"util/mapping.cpp\"\
    \n\nclass Mapping {\n public:\n  struct Combine {\n    Mapping operator()(const\
    \ Mapping& lhs, const Mapping& rhs) {\n      if (lhs.f.empty()) return rhs;\n\
    \      if (rhs.f.empty()) return lhs;\n      assert(lhs.f.size() == rhs.f.size());\n\
    \      int n = lhs.f.size();\n      vector<int> f(n);\n      rep(x, n) {\n   \
    \     int y = rhs.f[x];\n        f[x] = 0 <= y and y < n ? lhs.f[y] : y;\n   \
    \   }\n      return Mapping(move(f));\n    }\n  };\n\n private:\n  vector<int>\
    \ f;\n\n public:\n  Mapping() = default;\n  Mapping(int n) : f(n) { iota(all(f),\
    \ 0); }\n  Mapping(const vector<int>& f_) : f(f_) {}\n  Mapping(vector<int>&&\
    \ f_) : f(move(f_)) {}\n\n  int operator()(int x) { return f[x]; }\n};\n#line\
    \ 5 \"util/doubling.cpp\"\n\ntemplate <typename T = Mapping, typename Combine\
    \ = typename T::Combine>\nclass Doubling {\n private:\n  vector<T> data;\n  const\
    \ T base;\n  const T unit;\n  const Combine combine;\n\n public:\n  Doubling(T\
    \ base_ = {}, T unit_ = {}, Combine combine_ = {})\n      : data({base_}), base(base_),\
    \ unit(unit_), combine(combine_) {}\n\n private:\n  void prepare(ll n) {\n   \
    \ if (n <= 1) return;\n    int need = 64 - __builtin_clz(n-1);\n    rep(need -\
    \ data.size()) data.push_back(combine(data.back(), data.back()));\n  }\n\n public:\n\
    \  T pow(ll exp) {\n    prepare(exp);\n    T res = unit;\n    int i = 0;\n   \
    \ for (; exp; exp >>= 1, i++)\n      if (exp & 1) res = combine(res, data[i]);\n\
    \    return res;\n  }\n\n  static T pow(T base, ll exp, T unit = {}, Combine combine\
    \ = {}) {\n    T res = unit;\n    for (; exp; exp >>= 1, base = combine(base,\
    \ base))\n      if (exp & 1) res = combine(res, base);\n    return res;\n  }\n\
    };\n#line 5 \"math/squarematrix.cpp\"\n\ntemplate <typename M = ll>\nclass SquareMatrix\
    \ {\n public:\n  using arr = vector<M>;\n  using mat = vector<arr>;\n  int n;\n\
    \n private:\n  mat data;\n\n  SquareMatrix(int n_) : n(n_), data(n, arr(n)) {}\n\
    \  SquareMatrix(const mat& dat_) : n(dat_.size()), data(dat_) {}\n\n  bool operator==(const\
    \ SquareMatrix& rhs) const { return data == rhs.data; }\n  bool operator!=(const\
    \ SquareMatrix& rhs) const { return data != rhs.data; }\n\n  size_t size() const\
    \ { return n; }\n  arr& operator[](size_t k) { return data[k]; }\n  const arr&\
    \ operator[](size_t k) const { return data[k]; }\n\n  static SquareMatrix mul_unit(int\
    \ n) {\n    SquareMatrix res(n);\n    rep(i, n) res[i][i] = M(1);\n    return\
    \ res;\n  }\n\n  SquareMatrix operator*(const SquareMatrix& rhs) const {\n   \
    \ SquareMatrix res(n);\n    rep(i, n) rep(j, n) rep(k, n) res[i][j] += (data[i][k]\
    \ * rhs[k][j]);\n    return res;\n  }\n\n  arr operator*(const arr& rhs) const\
    \ {\n    arr res(n);\n    rep(i, n) rep(j, n) res[i] += data[i][j] * rhs[j];\n\
    \    return res;\n  }\n\n  SquareMatrix operator+(const SquareMatrix& rhs) const\
    \ {\n    SquareMatrix res(n);\n    for (size_t i = 0; i < n; i++)\n      for (size_t\
    \ j = 0; j < n; j++) res[i][j] = data[i][j] + rhs[i][j];\n    return res;\n  }\n\
    \n  SquareMatrix pow(ll exp) const {\n    using Doubling = Doubling<SquareMatrix,\
    \ multiplies<SquareMatrix>>;\n    return Doubling::pow(*this, exp, mul_unit(n));\n\
    \  }\n\n  SquareMatrix transpose() const {\n    SquareMatrix res = *this;\n  \
    \  rep(i, n) rep(j, i + 1, n) swap(res.data[i][j], res.data[j][i]);\n    return\
    \ res;\n  }\n};\n"
  code: "#pragma once\n\n#include \"template.cpp\"\n#include \"util/doubling.cpp\"\
    \n\ntemplate <typename M = ll>\nclass SquareMatrix {\n public:\n  using arr =\
    \ vector<M>;\n  using mat = vector<arr>;\n  int n;\n\n private:\n  mat data;\n\
    \n  SquareMatrix(int n_) : n(n_), data(n, arr(n)) {}\n  SquareMatrix(const mat&\
    \ dat_) : n(dat_.size()), data(dat_) {}\n\n  bool operator==(const SquareMatrix&\
    \ rhs) const { return data == rhs.data; }\n  bool operator!=(const SquareMatrix&\
    \ rhs) const { return data != rhs.data; }\n\n  size_t size() const { return n;\
    \ }\n  arr& operator[](size_t k) { return data[k]; }\n  const arr& operator[](size_t\
    \ k) const { return data[k]; }\n\n  static SquareMatrix mul_unit(int n) {\n  \
    \  SquareMatrix res(n);\n    rep(i, n) res[i][i] = M(1);\n    return res;\n  }\n\
    \n  SquareMatrix operator*(const SquareMatrix& rhs) const {\n    SquareMatrix\
    \ res(n);\n    rep(i, n) rep(j, n) rep(k, n) res[i][j] += (data[i][k] * rhs[k][j]);\n\
    \    return res;\n  }\n\n  arr operator*(const arr& rhs) const {\n    arr res(n);\n\
    \    rep(i, n) rep(j, n) res[i] += data[i][j] * rhs[j];\n    return res;\n  }\n\
    \n  SquareMatrix operator+(const SquareMatrix& rhs) const {\n    SquareMatrix\
    \ res(n);\n    for (size_t i = 0; i < n; i++)\n      for (size_t j = 0; j < n;\
    \ j++) res[i][j] = data[i][j] + rhs[i][j];\n    return res;\n  }\n\n  SquareMatrix\
    \ pow(ll exp) const {\n    using Doubling = Doubling<SquareMatrix, multiplies<SquareMatrix>>;\n\
    \    return Doubling::pow(*this, exp, mul_unit(n));\n  }\n\n  SquareMatrix transpose()\
    \ const {\n    SquareMatrix res = *this;\n    rep(i, n) rep(j, i + 1, n) swap(res.data[i][j],\
    \ res.data[j][i]);\n    return res;\n  }\n};\n"
  dependsOn:
  - template.cpp
  - util/doubling.cpp
  - util/mapping.cpp
  isVerificationFile: false
  path: math/squarematrix.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/squarematrix.cpp
layout: document
redirect_from:
- /library/math/squarematrix.cpp
- /library/math/squarematrix.cpp.html
title: math/squarematrix.cpp
---
