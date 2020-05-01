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


# :warning: math/garner-ntt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/garner-ntt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-01 11:42:13+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>
* :warning: <a href="../util/modint.cpp.html">util/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "util/modint.cpp"

// credit to @beet-aizu
constexpr ll bmds(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}
constexpr int brts(int x) { // primitive roots
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}
template <int X>
struct NTT {
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = modint<md>;
  vector<vector<M> > rts, rrts;

  void ensure_base(int n) {
    if ((int)rts.size() >= n) return;
    rts.resize(n);
    rrts.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!rts[i].empty()) continue;
      M w = pow(M(rt), (md - 1) / (i << 1));
      M rw = M(1) / w;
      rts[i].resize(i);
      rrts[i].resize(i);
      rts[i][0] = M(1);
      rrts[i][0] = M(1);
      for (int k = 1; k < i; k++) {
        rts[i][k] = rts[i][k - 1] * w;
        rrts[i][k] = rrts[i][k - 1] * rw;
      }
    }
  }

  void ntt(vector<M>& as, bool f) {
    int n = as.size();
    assert((n & (n - 1)) == 0);
    ensure_base(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (i > j) swap(as[i], as[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          M z = as[i + j + k] * (f ? rrts[i][k] : rts[i][k]);
          as[i + j + k] = as[j + k] - z;
          as[j + k] += z;
        }
      }
    }

    if (f) {
      M tmp = M(1) / M(n);
      for (int i = 0; i < n; i++) as[i] *= tmp;
    }
  }

  vector<M> multiply(vector<M> as, vector<M> bs) {
    int need = as.size() + bs.size() - 1;
    int sz = 1;
    while (sz < need) sz <<= 1;
    as.resize(sz, M(0));
    bs.resize(sz, M(0));

    ntt(as, 0);
    ntt(bs, 0);
    for (int i = 0; i < sz; i++) as[i] *= bs[i];
    ntt(as, 1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as, vector<int> bs) {
    vector<M> am(as.size()), bm(bs.size());
    for (int i = 0; i < (int)am.size(); i++) am[i] = M(as[i]);
    for (int i = 0; i < (int)bm.size(); i++) bm[i] = M(bs[i]);
    vector<M> cm = multiply(am, bm);
    vector<int> cs(cm.size());
    for (int i = 0; i < (int)cs.size(); i++) cs[i] = cm[i].value;
    return cs;
  }
};

struct Garner {
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a, int b, int md) {
    int res = 1;
    a = a % md;
    while (b) {
      if (b & 1) res = (ll)res * a % md;
      a = (ll)a * a % md;
      b >>= 1;
    }
    return res;
  }

  static constexpr int inv(int x, int md) { return pow(x, md - 2, md); }

  inline void garner(int &c0, int c1, int c2, int m01, int mod) {
    static constexpr int r01 = inv(ntt0.md, ntt1.md);
    static constexpr int r02 = inv(ntt0.md, ntt2.md);
    static constexpr int r12 = inv(ntt1.md, ntt2.md);

    c1 = (ll)(c1 - c0) * r01 % ntt1.md;
    if (c1 < 0) c1 += ntt1.md;

    c2 = (ll)(c2 - c0) * r02 % ntt2.md;
    c2 = (ll)(c2 - c1) * r12 % ntt2.md;
    if (c2 < 0) c2 += ntt2.md;

    c0 %= mod;
    c0 += (ll)c1 * ntt0.md % mod;
    if (c0 >= mod) c0 -= mod;
    c0 += (ll)c2 * m01 % mod;
    if (c0 >= mod) c0 -= mod;
  }

  inline void garner(vector<vector<int>> &cs, int mod) {
    int m01 = (ll)ntt0.md * ntt1.md % mod;
    int sz = cs[0].size();
    for (int i = 0; i < sz; i++) garner(cs[0][i], cs[1][i], cs[2][i], m01, mod);
  }

  vector<int> multiply(vector<int> as, vector<int> bs, int mod) {
    vector<vector<int>> cs(3);
    cs[0] = ntt0.multiply(as, bs);
    cs[1] = ntt1.multiply(as, bs);
    cs[2] = ntt2.multiply(as, bs);
    size_t sz = as.size() + bs.size() - 1;
    for (auto &v : cs) v.resize(sz);
    garner(cs, mod);
    return cs[0];
  }

  template <typename T>
  decltype(auto) multiply(vector<T> am, vector<T> bm) {
    vector<int> as(am.size()), bs(bm.size());
    for (int i = 0; i < (int)as.size(); i++) as[i] = am[i].v;
    for (int i = 0; i < (int)bs.size(); i++) bs[i] = bm[i].v;
    vector<int> cs = multiply(as, bs, T::mod);
    vector<T> cm(cs.size());
    for (int i = 0; i < (int)cm.size(); i++) cm[i] = T(cs[i]);
    return cm;
  }
} garner;
NTT<0> Garner::ntt0;
NTT<1> Garner::ntt1;
NTT<2> Garner::ntt2;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/garner-ntt.cpp"

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
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
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
template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
constexpr int INF = 1000000007;
constexpr ll INF_LL = 1'000'000'000'000'000'007;
#define EXIT(out) do { OUT(out); exit(0); } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl "\n"
#define __overload3(_1, _2, _3, name, ...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) _repeat(_repeat, __COUNTER__, times)
#define _repeat(_repeat, cnt, times) _repeat2(_repeat, cnt, times)
#define _repeat2(_repeat, cnt, times) repFromUntil(_repeat ## cnt, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name ## __until = (until); name < name ## __until; name++)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = (until)-1, name ## __from = (from); name >= name ## __from; name--)
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }
ll power(ll e, ll t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t & 1) res = (res * e) % mod;
    t >>= 1; e = (e * e) % mod;
  }
  return res;
}
ll choose(ll n, int r) {
  chmin(r, n-r);
  if (r < 0) return 0;
  ll res = 1;
  rep(i, r) res *= n-i, res /= i+1;
  return res;
}
template <typename T> T divceil(T m, T d) { assert(m >= 0 and d > 0); return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
string operator*(const string& s, int times) { string res = ""; rep(times) res += s; return res; }
struct Edge {
  int to; ll cost;
  Edge(int _to) : to(_to), cost(1) {}
  Edge(int _to, ll _cost) : to(_to), cost(_cost) {}
  operator int() { return to; }
};
using Graph = vector<vector<Edge>>;
// IO
// formatted version of following is at https://shino-sky.github.io/cp-lib/library/formatted_template.cpp.html
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
class MyScanner { public: int offset = 0; char nc(){ return getchar(); }
template <typename T> void input_integer(T& var) { var = 0; T sign = 1; int cc = nc(); for (;
cc < '0' || '9' < cc; cc = nc()) if (cc == '-') sign = -1; for (; '0' <= cc && cc <= '9'; cc =
nc()) var = (var << 3) + (var << 1) + cc - '0'; var = var * sign; var += offset; } int c() {
char c; while (c = nc(), c == ' ' or c == '\n'); return c; } MyScanner& operator>>(char& var)
{ var = c(); return *this; } MyScanner& operator>>(int& var) { input_integer<int>(var); return
*this; } MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; } MyScanner&
operator>>(string& var) { var = ""; int cc = nc(); for (; !isvisiblechar(cc); cc = nc()); for
(; isvisiblechar(cc); cc = nc()) var.push_back(cc); return *this; } template <typename T>
operator T() { T x; *this >> x; return x; } template <typename T> void operator()(T &t) { *
this >> t; } template <typename T, typename... Ts> void operator()(T &t, Ts &...ts) { *this >>
t; this->operator()(ts...); } template <typename Iter> void iter(Iter first, Iter last) {
while (first != last) *this >> *first, first++; } VI vi(int n) { VI res(n); iter(all(res));
return res; } VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] = vi(m); return res; } VLL
vll(int n) { VLL res(n); iter(all(res)); return res; } VVLL vvll(int n, int m) { VVLL res(n);
rep(i, n) res[i] = vll(m); return res; } template <typename T> vector<T> v(int n) { vector<T>
res(n); iter(all(res)); return res; } private: int isvisiblechar(int c) { return 0x21 <= c &&
c <= 0x7E; } } IN, IN1{-1}; class MyPrinter { public: int offset = 0; template <typename T>
void output_integer(T var) { var += offset; if (var == 0) { putchar('0'); return; } if (var <
0) putchar('-'), var = -var; char stack[32]; int stack_p = 0; while (var) stack[stack_p++] =
'0' + (var % 10), var /= 10; while (stack_p) putchar(stack[--stack_p]); } MyPrinter& operator
<<(char c) { putchar(c); return *this; } MyPrinter& operator<<(double x) { printf("%.10f", x);
return *this; } template <typename T> MyPrinter& operator<<(T var) { output_integer<T>(var);
return *this; } MyPrinter& operator<<(char* str_p) { while (*str_p) putchar(*(str_p++));
return *this; } MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar(*(str_p++));
return *this; } MyPrinter& operator<<(const string& str) { const char* p = str.c_str(); const
char* l = p + str.size(); while (p < l) putchar(*p++); return *this; } template <typename T>
void operator()(T x) { *this << x << newl; } template <typename T, typename... Ts> void
operator()(T x, Ts ...xs) { *this << x << " "; this->operator()(xs...); } template <typename
Iter> void iter(Iter s, Iter t) { if (s == t) *this << "\n"; else for (; s != t; s++) *this <<
*s << " \n"[next(s, 1) == t]; } } OUT, OUT1{1}; template <typename T, typename U> MyPrinter&
operator<<(MyPrinter& out, const pair<T, U>& var) { return out << var.first << " " << var.
second; } template <typename Tuple, size_t I, size_t N, enable_if_t<I == N>* = nullptr>
MyPrinter& tuple_impl(MyPrinter& out, const Tuple& var) { return out; } template <typename
Tuple, size_t I, size_t N, enable_if_t<I != N>* = nullptr> MyPrinter& tuple_impl(MyPrinter&
out, const Tuple& var) { out << get<I>(var) << " "; return tuple_impl<Tuple, I+1, N>(out, var)
; } template <typename... Ts> MyPrinter& operator<<(MyPrinter& out, const tuple<Ts...>& var) {
return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(out, var); } template <typename T, typename
U> MyScanner& operator>>(MyScanner& in, pair<T, U>& var) { return in >> var.first >> var.
second; } template <typename Tuple, size_t I, size_t N, enable_if_t<I == N>* = nullptr>
MyScanner& tuple_impl(MyScanner& in, Tuple& var) { return in; } template <typename Tuple,
size_t I, size_t N, enable_if_t<I != N>* = nullptr> MyScanner& tuple_impl(MyScanner& in, Tuple
& var) { in >> get<I>(var); return tuple_impl<Tuple, I+1, N>(in, var); } template <typename...
Ts> MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) { return tuple_impl<tuple<Ts...>,
0, sizeof...(Ts)>(in, var); }
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
os; } void dump_func() { debugos << newl; } template <class Head, class... Tail> void
dump_func(Head &&head, Tail &&...tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos
<< ", "; } dump_func(std::move(tail)...); }
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#pragma GCC diagnostic pop


#line 2 "util/modint.cpp"

#line 4 "util/modint.cpp"

template <ll> class modint;
template <ll MOD> constexpr modint<MOD> pow(modint<MOD>, ll);

template <ll MOD = 1000000007>
class modint {
public:
  ll value;

  constexpr modint(const ll x = 0) noexcept : value(x) {
    value %= MOD;
    if (value < 0) value += MOD;
  }
  constexpr bool operator==(const modint<MOD>& rhs) {
    return value == rhs.value;
  }
  constexpr bool operator!=(const modint<MOD>& rhs) {
    return value != rhs.value;
  }
  constexpr modint<MOD> operator-() const {
    return modint<MOD>(0) - *this;
  }
  constexpr modint<MOD> operator+(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) += rhs;
  }
  constexpr modint<MOD> operator-(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) -= rhs;
  }
  constexpr modint<MOD> operator*(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) *= rhs;
  }
  constexpr modint<MOD> operator/(const modint<MOD>& rhs) const {
    return modint<MOD>(*this) /= rhs;
  }
  constexpr modint<MOD>& operator+=(const modint<MOD>& rhs) {
    value += rhs.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  constexpr modint<MOD>& operator-=(const modint<MOD>& rhs) {
    if (value < rhs.value) value += MOD;
    value -= rhs.value;
    return *this;
  }
  constexpr modint<MOD>& operator*=(const modint<MOD>& rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }
  constexpr modint<MOD>& operator/=(const modint<MOD>& rhs) {
    return *this *= pow(rhs, MOD - 2);
  }
  constexpr modint<MOD>& operator++() {
    return *this += 1;
  }
  constexpr modint<MOD> operator++(int) {
    modint<MOD> tmp(*this);
    ++(*this);
    return tmp;
  }
  constexpr modint<MOD>& operator--() {
    return *this -= 1;
  }
  constexpr modint<MOD> operator--(int) {
    modint<MOD> tmp(*this);
    --(*this);
    return tmp;
  }
  constexpr operator int() const {
    return (int)value;
  }
  constexpr operator ll() const {
    return value;
  }
};


template <typename OutStream, ll MOD>
OutStream& operator<<(OutStream& out, modint<MOD> n) {
  out << n.value;
  return out;
}

template <typename InStream, ll MOD>
InStream& operator>>(InStream& in, modint<MOD>& n) {
  ll var; in >> var; n = modint<MOD>(var);
  return in;
}

template <ll MOD>
constexpr modint<MOD> pow(modint<MOD> base, ll exp) {
  modint<MOD> res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    exp /= 2;
  }
  return res;
}

// O(r + log MOD)
template <ll MOD>
modint<MOD> choose(int n, int r) {
  chmin(r, n-r);
  if (r < 0) return modint<MOD>(0);
  modint<MOD> nu = 1, de = 1;
  rep(i, r) nu *= n-i, de *= i+1;
  return nu / de;
}
#line 5 "math/garner-ntt.cpp"

// credit to @beet-aizu
constexpr ll bmds(int x) {
  const ll v[] = {1012924417, 924844033, 998244353, 897581057, 645922817};
  return v[x];
}
constexpr int brts(int x) { // primitive roots
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}
template <int X>
struct NTT {
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = modint<md>;
  vector<vector<M> > rts, rrts;

  void ensure_base(int n) {
    if ((int)rts.size() >= n) return;
    rts.resize(n);
    rrts.resize(n);
    for (int i = 1; i < n; i <<= 1) {
      if (!rts[i].empty()) continue;
      M w = pow(M(rt), (md - 1) / (i << 1));
      M rw = M(1) / w;
      rts[i].resize(i);
      rrts[i].resize(i);
      rts[i][0] = M(1);
      rrts[i][0] = M(1);
      for (int k = 1; k < i; k++) {
        rts[i][k] = rts[i][k - 1] * w;
        rrts[i][k] = rrts[i][k - 1] * rw;
      }
    }
  }

  void ntt(vector<M>& as, bool f) {
    int n = as.size();
    assert((n & (n - 1)) == 0);
    ensure_base(n);

    for (int i = 0, j = 1; j + 1 < n; j++) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (i > j) swap(as[i], as[j]);
    }

    for (int i = 1; i < n; i <<= 1) {
      for (int j = 0; j < n; j += i * 2) {
        for (int k = 0; k < i; k++) {
          M z = as[i + j + k] * (f ? rrts[i][k] : rts[i][k]);
          as[i + j + k] = as[j + k] - z;
          as[j + k] += z;
        }
      }
    }

    if (f) {
      M tmp = M(1) / M(n);
      for (int i = 0; i < n; i++) as[i] *= tmp;
    }
  }

  vector<M> multiply(vector<M> as, vector<M> bs) {
    int need = as.size() + bs.size() - 1;
    int sz = 1;
    while (sz < need) sz <<= 1;
    as.resize(sz, M(0));
    bs.resize(sz, M(0));

    ntt(as, 0);
    ntt(bs, 0);
    for (int i = 0; i < sz; i++) as[i] *= bs[i];
    ntt(as, 1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as, vector<int> bs) {
    vector<M> am(as.size()), bm(bs.size());
    for (int i = 0; i < (int)am.size(); i++) am[i] = M(as[i]);
    for (int i = 0; i < (int)bm.size(); i++) bm[i] = M(bs[i]);
    vector<M> cm = multiply(am, bm);
    vector<int> cs(cm.size());
    for (int i = 0; i < (int)cs.size(); i++) cs[i] = cm[i].value;
    return cs;
  }
};

struct Garner {
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a, int b, int md) {
    int res = 1;
    a = a % md;
    while (b) {
      if (b & 1) res = (ll)res * a % md;
      a = (ll)a * a % md;
      b >>= 1;
    }
    return res;
  }

  static constexpr int inv(int x, int md) { return pow(x, md - 2, md); }

  inline void garner(int &c0, int c1, int c2, int m01, int mod) {
    static constexpr int r01 = inv(ntt0.md, ntt1.md);
    static constexpr int r02 = inv(ntt0.md, ntt2.md);
    static constexpr int r12 = inv(ntt1.md, ntt2.md);

    c1 = (ll)(c1 - c0) * r01 % ntt1.md;
    if (c1 < 0) c1 += ntt1.md;

    c2 = (ll)(c2 - c0) * r02 % ntt2.md;
    c2 = (ll)(c2 - c1) * r12 % ntt2.md;
    if (c2 < 0) c2 += ntt2.md;

    c0 %= mod;
    c0 += (ll)c1 * ntt0.md % mod;
    if (c0 >= mod) c0 -= mod;
    c0 += (ll)c2 * m01 % mod;
    if (c0 >= mod) c0 -= mod;
  }

  inline void garner(vector<vector<int>> &cs, int mod) {
    int m01 = (ll)ntt0.md * ntt1.md % mod;
    int sz = cs[0].size();
    for (int i = 0; i < sz; i++) garner(cs[0][i], cs[1][i], cs[2][i], m01, mod);
  }

  vector<int> multiply(vector<int> as, vector<int> bs, int mod) {
    vector<vector<int>> cs(3);
    cs[0] = ntt0.multiply(as, bs);
    cs[1] = ntt1.multiply(as, bs);
    cs[2] = ntt2.multiply(as, bs);
    size_t sz = as.size() + bs.size() - 1;
    for (auto &v : cs) v.resize(sz);
    garner(cs, mod);
    return cs[0];
  }

  template <typename T>
  decltype(auto) multiply(vector<T> am, vector<T> bm) {
    vector<int> as(am.size()), bs(bm.size());
    for (int i = 0; i < (int)as.size(); i++) as[i] = am[i].v;
    for (int i = 0; i < (int)bs.size(); i++) bs[i] = bm[i].v;
    vector<int> cs = multiply(as, bs, T::mod);
    vector<T> cm(cs.size());
    for (int i = 0; i < (int)cm.size(); i++) cm[i] = T(cs[i]);
    return cm;
  }
} garner;
NTT<0> Garner::ntt0;
NTT<1> Garner::ntt1;
NTT<2> Garner::ntt2;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
