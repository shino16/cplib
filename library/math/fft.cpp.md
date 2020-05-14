---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/fft.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/fft.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 23:32:59+09:00




## Depends on

* :warning: <a href="../geometry/Pt.cpp.html">geometry/Pt.cpp</a>
* :question: <a href="../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "geometry/Pt.cpp"
#include "template.cpp"

namespace FFT {
using dbl = double;

using complex = Pt<dbl>;

inline complex conj(complex a) { return complex(a.x, -a.y); }

int base = 1;
vector<complex> root = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const dbl PI = asinl(1) * 2;

void prepare(int nbase) {
  if (nbase <= base) return;

  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

  root.resize(1 << nbase);

  rep(b, base, nbase) {
    dbl theta = 2 * PI / (1 << (b + 1));
    for (int i = 1 << (b - 1); i < (1 << b); i++) {
      root[i << 1] = root[i];
      dbl aug = theta * (2 * i + 1 - (1 << b));
      root[(i << 1) + 1] = complex(cos(aug), sin(aug));
    }
  }
}

template <typename T, typename U>
vector<T> cast(const vector<U>& v) {
  vector<T> res(v.size());
  if (is_integral<T>::value)
    rep(i, v.size()) res[i] = T(round(v[i]));
  else
    copy(all(v), res.begin());
  return res;
}

void fft(vector<complex>& A) {
  int n = A.size();
  assert((n & (n - 1)) == 0);

  int zeros = __builtin_ctz(n);
  prepare(zeros + 1);
  int shift = base - zeros;
  rep(i, n) if (i < (rev[i] >> shift)) swap(A[i], A[rev[i] >> shift]);

  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        complex z = A[i + j + k] * root[j + k];
        A[i + j + k] = A[i + j] - z;
        A[i + j] += z;
      }
    }
  }
}

template <typename T>
vector<T> multiply(const vector<T>& A, const vector<T>& B) {
  int need = A.size() + B.size() - 1;
  int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));

  vector<complex> fa(sz);
  rep(i, A.size()) fa[i].x = dbl(A[i]);
  rep(i, B.size()) fa[i].y = dbl(B[i]);
  fft(fa);

  complex r(0, -0.25 / sz);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    if (i != j) fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    fa[i] = z;
  }
  fft(fa);

  vector<T> res(need);
  rep(i, need) res[i] = fa[i].x;

  return res;
}

template <typename T>
vector<dbl> div(vector<T>& A, vector<T>& B) {
  static vector<dbl> q_rev;
  static vector<vector<dbl>> t;  // t[i] * B == 0 mod x^2^i

  while (B.back() == 0) B.pop_back();
  if (not equal(all(B), rall(q_rev))) {
    q_rev.resize(B.size());
    copy(rall(B), q_rev.begin());
    t.clear();
    t.emplace_back(vector<dbl>{1 / q_rev[0]});
  }

  int n = A.size(), m = B.size();
  int k = 32 - __builtin_clz(n - m);  // ceil(log2(n-m+1))
  rep((1 << k) - n) A.emplace_back(dbl(0));
  n = A.size();

  rep(k + 1 - t.size()) {
    vector<dbl> next = multiply(multiply(t.back(), t.back()), q_rev);
    next.resize(1 << t.size());
    for (auto& a : next) a *= -1;
    rep(i, t.back().size()) next[i] += t.back()[i] * 2;
    t.emplace_back(move(next));
  }

  reverse(all(A));
  vector<dbl> res = multiply(t[k], vector<dbl>(all(A)));
  res.resize(n - m + 1);
  reverse(all(A));
  reverse(all(res));

  return res;
}

template <typename Vector>
vector<dbl> div(Vector&& A, Vector&& B) {
  return div(A, B);
}

template <typename T>
pair<vector<dbl>, vector<dbl>> divmod(vector<T>& A, vector<T>& B,
                                      dbl eps = 1e-9) {
  vector<dbl> q = div(A, B);
  vector<dbl> r = multiply(q, cast<dbl>(B));
  r.resize(A.size());
  rep(i, r.size()) r[i] = A[i] - r[i];
  while (r.size() > 1 and abs(r.back()) < eps) r.pop_back();
  return make_pair(q, r);
}

template <typename Vector>
pair<vector<dbl>, vector<dbl>> divmod(Vector&& A, Vector&& B, dbl eps = 1e-9) {
  return divmod(A, B, eps);
}

template <typename Vector>
vector<dbl> mod(Vector&& A, Vector&& B, dbl eps = 1e-9) {
  return divmod(A, B, eps).second;
}

};  // namespace FFT

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/fft.cpp"

#line 2 "geometry/Pt.cpp"

#line 2 "template.cpp"

#ifndef LOCAL
#pragma GCC diagnostic warning "-w"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VB = vector<bool>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl '\n'

// loops rep(until) / rep(var, until) / rep(var, from, until) / repr (reversed order)
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define rep(...) OVERLOAD3(__VA_ARGS__, REPEAT_FROM_UNTIL, REPEAT_UNTIL, REPEAT)(__VA_ARGS__)
#define REPEAT(times) REPEAT_CNT(_repeat, __COUNTER__, times)
#define REPEAT_CNT(_repeat, cnt, times) REPEAT_CNT_CAT(_repeat, cnt, times)
#define REPEAT_CNT_CAT(_repeat, cnt, times) REPEAT_FROM_UNTIL(_repeat ## cnt, 0, times)
#define REPEAT_UNTIL(name, times) REPEAT_FROM_UNTIL(name, 0, times)
#define REPEAT_FROM_UNTIL(name, from, until) for (int name = from, name ## __until = (until); name < name ## __until; name++)
#define repr(...) OVERLOAD3(__VA_ARGS__, REPR_FROM_UNTIL, REPR_UNTIL, REPEAT)(__VA_ARGS__)
#define REPR_UNTIL(name, times) REPR_FROM_UNTIL(name, 0, times)
#define REPR_FROM_UNTIL(name, from, until) for (int name = (until)-1, name ## __from = (from); name >= name ## __from; name--)

template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1; for (; t; t >>= 1, (e *= e) %= mod) if (t & 1) (res *= e) %= mod; return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r); if (r < 0) return 0; ll res = 1; rep(i, r) res *= n-i, res /= i+1; return res;
}
template <typename T> T divceil(T m, T d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// debug stuff
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *itr;
itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, set<T>& set_var) { os << "{"; repi(itr,
set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}"; return
os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const pair<T, U
>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func() {
debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail &&...
tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(std::move(
tail)...); }
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#pragma GCC diagnostic pop


#line 4 "geometry/Pt.cpp"

template <typename T = int>
struct Pt {
  T x, y;

  Pt(T x_ = 0, T y_ = 0): x(x_), y(y_) { }

  Pt operator +(const Pt<T>& rhs) const {
    return Pt(x+rhs.x, y+rhs.y);
  }
  Pt operator -(const Pt<T>& rhs) const {
    return Pt(x-rhs.x, y-rhs.y);
  }
  Pt operator -() const {
    return Pt(-x, -y);
  }
  Pt operator *(const Pt<T>& rhs) const {
    return Pt(x*rhs.x - y*rhs.y, x*rhs.y + y*rhs.x);
  }
  Pt operator *(const T rhs) const {
    return Pt(x*rhs, y*rhs);
  }
  Pt& operator +=(const Pt<T>& rhs) const {
    return *this = *this + rhs;
  }
  Pt& operator -=(const Pt<T>& rhs) const {
    return *this = *this - rhs;
  }
  Pt& operator *=(const Pt<T>& rhs) {
    return *this = *this * rhs;
  }
  Pt& operator *=(const T rhs) const {
    return *this = *this * rhs;
  }
  bool operator ==(const Pt<T>& rhs) const {
    return x == rhs.x and y == rhs.y;
  }
  bool operator !=(const Pt<T>& rhs) const {
    return not (*this == rhs);
  }
  double abs() const {
    return hypot(x, y);
  }
  T dot(const Pt<T>& rhs) const {
    return x*rhs.x + y*rhs.y;
  }
  T det(const Pt<T>& rhs) const {
    return x*rhs.y - y*rhs.x;
  }
};

template <typename OutStream, typename T>
OutStream& operator<<(OutStream& out, const Pt<T>& var) {
  return out << var.x << " " << var.y;
}

template <typename InStream, typename T>
InStream& operator>>(InStream& in, Pt<T>& var) {
  return in >> var.x >> var.y;
}
#line 5 "math/fft.cpp"

namespace FFT {
using dbl = double;

using complex = Pt<dbl>;

inline complex conj(complex a) { return complex(a.x, -a.y); }

int base = 1;
vector<complex> root = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const dbl PI = asinl(1) * 2;

void prepare(int nbase) {
  if (nbase <= base) return;

  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));

  root.resize(1 << nbase);

  rep(b, base, nbase) {
    dbl theta = 2 * PI / (1 << (b + 1));
    for (int i = 1 << (b - 1); i < (1 << b); i++) {
      root[i << 1] = root[i];
      dbl aug = theta * (2 * i + 1 - (1 << b));
      root[(i << 1) + 1] = complex(cos(aug), sin(aug));
    }
  }
}

template <typename T, typename U>
vector<T> cast(const vector<U>& v) {
  vector<T> res(v.size());
  if (is_integral<T>::value)
    rep(i, v.size()) res[i] = T(round(v[i]));
  else
    copy(all(v), res.begin());
  return res;
}

void fft(vector<complex>& A) {
  int n = A.size();
  assert((n & (n - 1)) == 0);

  int zeros = __builtin_ctz(n);
  prepare(zeros + 1);
  int shift = base - zeros;
  rep(i, n) if (i < (rev[i] >> shift)) swap(A[i], A[rev[i] >> shift]);

  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        complex z = A[i + j + k] * root[j + k];
        A[i + j + k] = A[i + j] - z;
        A[i + j] += z;
      }
    }
  }
}

template <typename T>
vector<T> multiply(const vector<T>& A, const vector<T>& B) {
  int need = A.size() + B.size() - 1;
  int sz = need <= 1 ? 1 : 1 << (32 - __builtin_clz(need - 1));

  vector<complex> fa(sz);
  rep(i, A.size()) fa[i].x = dbl(A[i]);
  rep(i, B.size()) fa[i].y = dbl(B[i]);
  fft(fa);

  complex r(0, -0.25 / sz);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    complex z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    if (i != j) fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    fa[i] = z;
  }
  fft(fa);

  vector<T> res(need);
  rep(i, need) res[i] = fa[i].x;

  return res;
}

template <typename T>
vector<dbl> div(vector<T>& A, vector<T>& B) {
  static vector<dbl> q_rev;
  static vector<vector<dbl>> t;  // t[i] * B == 0 mod x^2^i

  while (B.back() == 0) B.pop_back();
  if (not equal(all(B), rall(q_rev))) {
    q_rev.resize(B.size());
    copy(rall(B), q_rev.begin());
    t.clear();
    t.emplace_back(vector<dbl>{1 / q_rev[0]});
  }

  int n = A.size(), m = B.size();
  int k = 32 - __builtin_clz(n - m);  // ceil(log2(n-m+1))
  rep((1 << k) - n) A.emplace_back(dbl(0));
  n = A.size();

  rep(k + 1 - t.size()) {
    vector<dbl> next = multiply(multiply(t.back(), t.back()), q_rev);
    next.resize(1 << t.size());
    for (auto& a : next) a *= -1;
    rep(i, t.back().size()) next[i] += t.back()[i] * 2;
    t.emplace_back(move(next));
  }

  reverse(all(A));
  vector<dbl> res = multiply(t[k], vector<dbl>(all(A)));
  res.resize(n - m + 1);
  reverse(all(A));
  reverse(all(res));

  return res;
}

template <typename Vector>
vector<dbl> div(Vector&& A, Vector&& B) {
  return div(A, B);
}

template <typename T>
pair<vector<dbl>, vector<dbl>> divmod(vector<T>& A, vector<T>& B,
                                      dbl eps = 1e-9) {
  vector<dbl> q = div(A, B);
  vector<dbl> r = multiply(q, cast<dbl>(B));
  r.resize(A.size());
  rep(i, r.size()) r[i] = A[i] - r[i];
  while (r.size() > 1 and abs(r.back()) < eps) r.pop_back();
  return make_pair(q, r);
}

template <typename Vector>
pair<vector<dbl>, vector<dbl>> divmod(Vector&& A, Vector&& B, dbl eps = 1e-9) {
  return divmod(A, B, eps);
}

template <typename Vector>
vector<dbl> mod(Vector&& A, Vector&& B, dbl eps = 1e-9) {
  return divmod(A, B, eps).second;
}

};  // namespace FFT

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

