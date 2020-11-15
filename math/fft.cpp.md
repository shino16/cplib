---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/Pt.cpp
    title: geometry/Pt.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fft.cpp\"\n\n#line 2 \"geometry/Pt.cpp\"\n\n#line 2\
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
    #else\n#define dump(...) ({})\n#endif\n#pragma GCC diagnostic pop\n\n\n#line 4\
    \ \"geometry/Pt.cpp\"\n\ntemplate <typename T = int>\nstruct Pt {\n  T x, y;\n\
    \n  Pt(T x_ = 0, T y_ = 0): x(x_), y(y_) { }\n\n  Pt operator +(const Pt<T>& rhs)\
    \ const {\n    return Pt(x+rhs.x, y+rhs.y);\n  }\n  Pt operator -(const Pt<T>&\
    \ rhs) const {\n    return Pt(x-rhs.x, y-rhs.y);\n  }\n  Pt operator -() const\
    \ {\n    return Pt(-x, -y);\n  }\n  Pt operator *(const Pt<T>& rhs) const {\n\
    \    return Pt(x*rhs.x - y*rhs.y, x*rhs.y + y*rhs.x);\n  }\n  Pt operator *(const\
    \ T rhs) const {\n    return Pt(x*rhs, y*rhs);\n  }\n  Pt& operator +=(const Pt<T>&\
    \ rhs) {\n    return *this = *this + rhs;\n  }\n  Pt& operator -=(const Pt<T>&\
    \ rhs) {\n    return *this = *this - rhs;\n  }\n  Pt& operator *=(const Pt<T>&\
    \ rhs) {\n    return *this = *this * rhs;\n  }\n  Pt& operator *=(const T rhs)\
    \ {\n    return *this = *this * rhs;\n  }\n  bool operator ==(const Pt<T>& rhs)\
    \ const {\n    return x == rhs.x and y == rhs.y;\n  }\n  bool operator !=(const\
    \ Pt<T>& rhs) const {\n    return not (*this == rhs);\n  }\n  double abs() const\
    \ {\n    return hypot(x, y);\n  }\n  T dot(const Pt<T>& rhs) const {\n    return\
    \ x*rhs.x + y*rhs.y;\n  }\n  T det(const Pt<T>& rhs) const {\n    return x*rhs.y\
    \ - y*rhs.x;\n  }\n};\n\ntemplate <typename OutStream, typename T>\nOutStream&\
    \ operator<<(OutStream& out, const Pt<T>& var) {\n  return out << var.x << \"\
    \ \" << var.y;\n}\n\ntemplate <typename InStream, typename T>\nInStream& operator>>(InStream&\
    \ in, Pt<T>& var) {\n  return in >> var.x >> var.y;\n}\n#line 5 \"math/fft.cpp\"\
    \n\nnamespace FFT {\nusing dbl = double;\n\nusing complex = Pt<dbl>;\n\ninline\
    \ complex conj(complex a) { return complex(a.x, -a.y); }\n\nint base = 1;\nvector<complex>\
    \ root = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nconst dbl PI = asinl(1)\
    \ * 2;\n\nvoid prepare(int nbase) {\n  if (nbase <= base) return;\n\n  rev.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++)\n    rev[i] = (rev[i >>\
    \ 1] >> 1) + ((i & 1) << (nbase - 1));\n\n  root.resize(1 << nbase);\n\n  rep(b,\
    \ base, nbase) {\n    dbl theta = 2 * PI / (1 << (b + 1));\n    for (int i = 1\
    \ << (b - 1); i < (1 << b); i++) {\n      root[i << 1] = root[i];\n      dbl aug\
    \ = theta * (2 * i + 1 - (1 << b));\n      root[(i << 1) + 1] = complex(cos(aug),\
    \ sin(aug));\n    }\n  }\n}\n\ntemplate <typename T, typename U>\nvector<T> cast(const\
    \ vector<U>& v) {\n  vector<T> res(v.size());\n  if (is_integral<T>::value)\n\
    \    rep(i, v.size()) res[i] = T(round(v[i]));\n  else\n    copy(all(v), res.begin());\n\
    \  return res;\n}\n\nvoid fft(vector<complex>& A) {\n  int n = A.size();\n  assert((n\
    \ & (n - 1)) == 0);\n\n  int zeros = __builtin_ctz(n);\n  prepare(zeros + 1);\n\
    \  int shift = base - zeros;\n  rep(i, n) if (i < (rev[i] >> shift)) swap(A[i],\
    \ A[rev[i] >> shift]);\n\n  for (int k = 1; k < n; k <<= 1) {\n    for (int i\
    \ = 0; i < n; i += 2 * k) {\n      for (int j = 0; j < k; j++) {\n        complex\
    \ z = A[i + j + k] * root[j + k];\n        A[i + j + k] = A[i + j] - z;\n    \
    \    A[i + j] += z;\n      }\n    }\n  }\n}\n\ntemplate <typename T>\nvector<T>\
    \ multiply(const vector<T>& A, const vector<T>& B) {\n  int need = A.size() +\
    \ B.size() - 1;\n  int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));\n\
    \n  vector<complex> fa(sz);\n  rep(i, A.size()) fa[i].x = dbl(A[i]);\n  rep(i,\
    \ B.size()) fa[i].y = dbl(B[i]);\n  fft(fa);\n\n  complex r(0, -0.25 / sz);\n\
    \  for (int i = 0; i <= (sz >> 1); i++) {\n    int j = (sz - i) & (sz - 1);\n\
    \    complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;\n    if (i != j) fa[j]\
    \ = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;\n    fa[i] = z;\n  }\n  fft(fa);\n\
    \n  vector<T> res(need);\n  rep(i, need) res[i] = fa[i].x;\n\n  return res;\n\
    }\n\ntemplate <typename T>\nvector<dbl> div(vector<T>& A, vector<T>& B) {\n  static\
    \ vector<dbl> q_rev;\n  static vector<vector<dbl>> t;  // t[i] * B == 0 mod x^2^i\n\
    \n  while (B.back() == 0) B.pop_back();\n  if (not equal(all(B), rall(q_rev)))\
    \ {\n    q_rev.resize(B.size());\n    copy(rall(B), q_rev.begin());\n    t.clear();\n\
    \    t.emplace_back(vector<dbl>{1 / q_rev[0]});\n  }\n\n  int n = A.size(), m\
    \ = B.size();\n  int k = 32 - __builtin_clz(n - m);  // ceil(log2(n-m+1))\n  rep((1\
    \ << k) - n) A.emplace_back(dbl(0));\n  n = A.size();\n\n  rep(k + 1 - t.size())\
    \ {\n    vector<dbl> next = multiply(multiply(t.back(), t.back()), q_rev);\n \
    \   next.resize(1 << t.size());\n    for (auto& a : next) a *= -1;\n    rep(i,\
    \ t.back().size()) next[i] += t.back()[i] * 2;\n    t.emplace_back(move(next));\n\
    \  }\n\n  reverse(all(A));\n  vector<dbl> res = multiply(t[k], vector<dbl>(all(A)));\n\
    \  res.resize(n - m + 1);\n  reverse(all(A));\n  reverse(all(res));\n\n  return\
    \ res;\n}\n\ntemplate <typename Vector>\nvector<dbl> div(Vector&& A, Vector&&\
    \ B) {\n  return div(A, B);\n}\n\ntemplate <typename T>\npair<vector<dbl>, vector<dbl>>\
    \ divmod(vector<T>& A, vector<T>& B,\n                                      dbl\
    \ eps = 1e-9) {\n  vector<dbl> q = div(A, B);\n  vector<dbl> r = multiply(q, cast<dbl>(B));\n\
    \  r.resize(A.size());\n  rep(i, r.size()) r[i] = A[i] - r[i];\n  while (r.size()\
    \ > 1 and abs(r.back()) < eps) r.pop_back();\n  return make_pair(q, r);\n}\n\n\
    template <typename Vector>\npair<vector<dbl>, vector<dbl>> divmod(Vector&& A,\
    \ Vector&& B, dbl eps = 1e-9) {\n  return divmod(A, B, eps);\n}\n\ntemplate <typename\
    \ Vector>\nvector<dbl> mod(Vector&& A, Vector&& B, dbl eps = 1e-9) {\n  return\
    \ divmod(A, B, eps).second;\n}\n\n};  // namespace FFT\n"
  code: "#pragma once\n\n#include \"geometry/Pt.cpp\"\n#include \"template.cpp\"\n\
    \nnamespace FFT {\nusing dbl = double;\n\nusing complex = Pt<dbl>;\n\ninline complex\
    \ conj(complex a) { return complex(a.x, -a.y); }\n\nint base = 1;\nvector<complex>\
    \ root = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\n\nconst dbl PI = asinl(1)\
    \ * 2;\n\nvoid prepare(int nbase) {\n  if (nbase <= base) return;\n\n  rev.resize(1\
    \ << nbase);\n  for (int i = 0; i < (1 << nbase); i++)\n    rev[i] = (rev[i >>\
    \ 1] >> 1) + ((i & 1) << (nbase - 1));\n\n  root.resize(1 << nbase);\n\n  rep(b,\
    \ base, nbase) {\n    dbl theta = 2 * PI / (1 << (b + 1));\n    for (int i = 1\
    \ << (b - 1); i < (1 << b); i++) {\n      root[i << 1] = root[i];\n      dbl aug\
    \ = theta * (2 * i + 1 - (1 << b));\n      root[(i << 1) + 1] = complex(cos(aug),\
    \ sin(aug));\n    }\n  }\n}\n\ntemplate <typename T, typename U>\nvector<T> cast(const\
    \ vector<U>& v) {\n  vector<T> res(v.size());\n  if (is_integral<T>::value)\n\
    \    rep(i, v.size()) res[i] = T(round(v[i]));\n  else\n    copy(all(v), res.begin());\n\
    \  return res;\n}\n\nvoid fft(vector<complex>& A) {\n  int n = A.size();\n  assert((n\
    \ & (n - 1)) == 0);\n\n  int zeros = __builtin_ctz(n);\n  prepare(zeros + 1);\n\
    \  int shift = base - zeros;\n  rep(i, n) if (i < (rev[i] >> shift)) swap(A[i],\
    \ A[rev[i] >> shift]);\n\n  for (int k = 1; k < n; k <<= 1) {\n    for (int i\
    \ = 0; i < n; i += 2 * k) {\n      for (int j = 0; j < k; j++) {\n        complex\
    \ z = A[i + j + k] * root[j + k];\n        A[i + j + k] = A[i + j] - z;\n    \
    \    A[i + j] += z;\n      }\n    }\n  }\n}\n\ntemplate <typename T>\nvector<T>\
    \ multiply(const vector<T>& A, const vector<T>& B) {\n  int need = A.size() +\
    \ B.size() - 1;\n  int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));\n\
    \n  vector<complex> fa(sz);\n  rep(i, A.size()) fa[i].x = dbl(A[i]);\n  rep(i,\
    \ B.size()) fa[i].y = dbl(B[i]);\n  fft(fa);\n\n  complex r(0, -0.25 / sz);\n\
    \  for (int i = 0; i <= (sz >> 1); i++) {\n    int j = (sz - i) & (sz - 1);\n\
    \    complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;\n    if (i != j) fa[j]\
    \ = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;\n    fa[i] = z;\n  }\n  fft(fa);\n\
    \n  vector<T> res(need);\n  rep(i, need) res[i] = fa[i].x;\n\n  return res;\n\
    }\n\ntemplate <typename T>\nvector<dbl> div(vector<T>& A, vector<T>& B) {\n  static\
    \ vector<dbl> q_rev;\n  static vector<vector<dbl>> t;  // t[i] * B == 0 mod x^2^i\n\
    \n  while (B.back() == 0) B.pop_back();\n  if (not equal(all(B), rall(q_rev)))\
    \ {\n    q_rev.resize(B.size());\n    copy(rall(B), q_rev.begin());\n    t.clear();\n\
    \    t.emplace_back(vector<dbl>{1 / q_rev[0]});\n  }\n\n  int n = A.size(), m\
    \ = B.size();\n  int k = 32 - __builtin_clz(n - m);  // ceil(log2(n-m+1))\n  rep((1\
    \ << k) - n) A.emplace_back(dbl(0));\n  n = A.size();\n\n  rep(k + 1 - t.size())\
    \ {\n    vector<dbl> next = multiply(multiply(t.back(), t.back()), q_rev);\n \
    \   next.resize(1 << t.size());\n    for (auto& a : next) a *= -1;\n    rep(i,\
    \ t.back().size()) next[i] += t.back()[i] * 2;\n    t.emplace_back(move(next));\n\
    \  }\n\n  reverse(all(A));\n  vector<dbl> res = multiply(t[k], vector<dbl>(all(A)));\n\
    \  res.resize(n - m + 1);\n  reverse(all(A));\n  reverse(all(res));\n\n  return\
    \ res;\n}\n\ntemplate <typename Vector>\nvector<dbl> div(Vector&& A, Vector&&\
    \ B) {\n  return div(A, B);\n}\n\ntemplate <typename T>\npair<vector<dbl>, vector<dbl>>\
    \ divmod(vector<T>& A, vector<T>& B,\n                                      dbl\
    \ eps = 1e-9) {\n  vector<dbl> q = div(A, B);\n  vector<dbl> r = multiply(q, cast<dbl>(B));\n\
    \  r.resize(A.size());\n  rep(i, r.size()) r[i] = A[i] - r[i];\n  while (r.size()\
    \ > 1 and abs(r.back()) < eps) r.pop_back();\n  return make_pair(q, r);\n}\n\n\
    template <typename Vector>\npair<vector<dbl>, vector<dbl>> divmod(Vector&& A,\
    \ Vector&& B, dbl eps = 1e-9) {\n  return divmod(A, B, eps);\n}\n\ntemplate <typename\
    \ Vector>\nvector<dbl> mod(Vector&& A, Vector&& B, dbl eps = 1e-9) {\n  return\
    \ divmod(A, B, eps).second;\n}\n\n};  // namespace FFT\n"
  dependsOn:
  - geometry/Pt.cpp
  - template.cpp
  isVerificationFile: false
  path: math/fft.cpp
  requiredBy: []
  timestamp: '2020-05-26 19:55:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fft.cpp
layout: document
redirect_from:
- /library/math/fft.cpp
- /library/math/fft.cpp.html
title: math/fft.cpp
---
