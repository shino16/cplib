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


# :heavy_check_mark: verify/BIT_2D.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8418d1d706cd73548f9f16f1d55ad6e">verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/BIT_2D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-28 16:34:23+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data-structure/bit_2d.cpp.html">data-structure/bit_2d.cpp</a>
* :heavy_check_mark: <a href="../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include "template.cpp"
#include "data-structure/bit_2d.cpp"

int main() {
  int h = IN, w = IN, T = IN, q = IN;

  queue<pair<int, PII>> trans;
  BIT_2D A(h, w), B(h, w);

  rep(q) {
    int t = IN, cmd = IN, r = IN1, c = IN1;

    while (not trans.empty() and trans.front().first <= t) {
      PII p; tie(ignore, p) = trans.front(); trans.pop();
      A.add(p.first, p.second, -1);
      B.add(p.first, p.second, +1);
    }

    if (cmd == 0) {
      A.add(r, c, +1);
      trans.emplace(t+T, PII{r, c});
    } else if (cmd == 1) {
      if (B.sum(r, c, r+1, c+1))
        B.add(r, c, -1);
    } else {
      int r2 = IN, c2 = IN;
      OUT(B.sum(r, c, r2, c2), A.sum(r, c, r2, c2));
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/BIT_2D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#line 1 "template.cpp"

#ifndef LOCAL
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
#define __overload3(_1, _2, _3, name, ...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(_repeat\
__LINE__, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = (until)-1, name##__from = (from); name >= name##__from; name--)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define newl "\n"
template <typename T, typename U>
bool chmin(T& var, U x) { if (var > x) { var = x; return true; } else return false; }
template <typename T, typename U>
bool chmax(T& var, U x) { if (var < x) { var = x; return true; } else return false; }
template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }
ll power(ll e, int t, ll mod = INF_LL) {
  ll res = 1;
  while (t) {
    if (t & 1) res = (res * e) % mod;
    t >>= 1; e = (e * e) % mod;
  }
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
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
class MyScanner { public: int offset = 0; char nc(){ return getchar(); }
template <typename T> void input_integer(T& var) { var = 0; T sign = 1; int cc = nc(); for (;
cc<'0' || '9'<cc; cc = nc()) if (cc == '-') sign = -1; for (; '0' <= cc && cc <= '9'; cc = nc(
)) var = (var << 3) + (var << 1) + cc - '0'; var = var * sign; var += offset; } int c() { char
c; while (c = nc(), c == ' ' or c == '\n'); return c; } MyScanner& operator>>(char& var) { var
= c(); return *this; } MyScanner& operator>>(int& var) { input_integer<int>(var); return *this
; } MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; } MyScanner&
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
#pragma GCC diagnostic warning "-Wmisleading-indentation"
#line 1 "data-structure/bit_2d.cpp"

class BIT_2D {
private:
  const int h, w;
  vector<vector<ll>> data;
public:
  BIT_2D(int h, int w): h(h), w(w), data(h+1, vector<ll>(w+1)) { }
  void add(int r, int c, ll v) {
    r++; c++;
    int c0 = c;
    for (; r <= h; r += r & -r)
      for (c = c0; c <= w; c += c & -c)
        data[r][c] += v;
  }
  // sum over [(0, 0), (r, c))
  ll sum(int r, int c) {
    ll res = 0;
    int c0 = c;
    for (; r > 0; r -= r & -r)
      for (c = c0; c > 0; c -= c & -c)
        res += data[r][c];
    return res;
  }
  // sum over [(r1, c1), (r2, c2))
  ll sum(int r1, int c1, int r2, int c2) {
    return sum(r1, c1) + sum(r2, c2) - sum(r1, c2) - sum(r2, c1);
  }
  void assign(int r, int c, ll v) {
    add(r, c, v - sum(r, c, r+1, c+1));
  }
  bool chmax(int r, int c, ll v) {
    if (sum(r, c, r+1, c+1) < v) {
      assign(r, c, v);
      return true;
    } else return false;
  }
};
#line 5 "verify/BIT_2D.test.cpp"

int main() {
  int h = IN, w = IN, T = IN, q = IN;

  queue<pair<int, PII>> trans;
  BIT_2D A(h, w), B(h, w);

  rep(q) {
    int t = IN, cmd = IN, r = IN1, c = IN1;

    while (not trans.empty() and trans.front().first <= t) {
      PII p; tie(ignore, p) = trans.front(); trans.pop();
      A.add(p.first, p.second, -1);
      B.add(p.first, p.second, +1);
    }

    if (cmd == 0) {
      A.add(r, c, +1);
      trans.emplace(t+T, PII{r, c});
    } else if (cmd == 1) {
      if (B.sum(r, c, r+1, c+1))
        B.add(r, c, -1);
    } else {
      int r2 = IN, c2 = IN;
      OUT(B.sum(r, c, r2, c2), A.sum(r, c, r2, c2));
    }
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

