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


# :heavy_check_mark: graph/strongly-connected-components.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly-connected-components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 12:26:25+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>
* :heavy_check_mark: <a href="../util/fix.cpp.html">util/fix.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/0366.test.cpp.html">verify/aoj/0366.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"
#include "util/fix.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/strongly-connected-components.cpp"

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
#define newl '\n'
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
operator>>(string& var) { var = ""; int cc = nc(); for (; !isgraph(cc); cc = nc()); for
(; isgraph(cc); cc = nc()) var.push_back(cc); return *this; } template <size_t N>
MyScanner& operator>>(bitset<N>& var) { ll v; input_integer<ll>(v); var = bitset<N>(v); return
*this; } template <typename T> operator T() { T x; *this >> x; return x; } template <typename
T> void operator()(T &t) { *this >> t; } template <typename T, typename... Ts> void operator()
(T &t, Ts &...ts) { *this >> t; this->operator()(ts...); } template <typename Iter> void iter
(Iter first, Iter last) { while (first != last) *this >> *first, first++; } VI vi(int n) { VI
res(n); iter(all(res)); return res; } VVI vvi(int n, int m) { VVI res(n); rep(i, n) res[i] =
vi(m); return res; } VLL vll(int n) { VLL res(n); iter(all(res)); return res; } VVLL vvll(int
n, int m) { VVLL res(n); rep(i, n) res[i] = vll(m); return res; } template <typename T> vector
<T> v(int n) { vector<T> res(n); iter(all(res)); return res; } } IN, IN1{-1}; class MyPrinter
{ public: int offset = 0; template <typename T> void output_integer(T var) { var += offset; if
(var == 0) { putchar('0'); return; } if (var < 0) putchar('-'), var = -var; char stack[32];
int stack_p = 0; while (var) stack[stack_p++] = '0' + (var % 10), var /= 10; while (stack_p)
putchar(stack[--stack_p]); } MyPrinter& operator<<(char c) { putchar(c); return *this; }
MyPrinter& operator<<(double x) { printf("%.10f", x); return *this; } template <typename T>
MyPrinter& operator<<(T var) { output_integer<T>(var); return *this; } MyPrinter& operator<<(
char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; } MyPrinter& operator<<(const
char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; } MyPrinter& operator<<(const
string& str) { const char* p = str.c_str(); const char* l = p + str.size(); while (p < l)
putchar(*p++); return *this; } template <typename T> void operator()(T x) { *this << x << newl
; } template <typename T, typename... Ts> void operator()(T x, Ts ...xs) { *this << x << " ";
this->operator()(xs...); } template <typename Iter> void iter(Iter s, Iter t) { if (s == t) *
this << "\n"; else for (; s != t; s++) *this << *s << " \n"[next(s, 1) == t]; } } OUT, OUT1{1}
; template <typename T, typename U> MyPrinter& operator<<(MyPrinter& out, const pair<T, U>&
var) { return out << var.first << " " << var.second; } template <typename Tuple, size_t I,
size_t N, enable_if_t<I == N>* = nullptr> MyPrinter& tuple_impl(MyPrinter& out, const Tuple&
var) { return out; } template <typename Tuple, size_t I, size_t N, enable_if_t<I != N>* =
nullptr> MyPrinter& tuple_impl(MyPrinter& out, const Tuple& var) { out << get<I>(var) << " ";
return tuple_impl<Tuple, I+1, N>(out, var); } template <typename... Ts> MyPrinter& operator<<(
MyPrinter& out, const tuple<Ts...>& var) { return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(
out, var); } template <typename T, typename U> MyScanner& operator>>(MyScanner& in, pair<T, U>
& var) { return in >> var.first >> var.second; } template <typename Tuple, size_t I, size_t N,
enable_if_t<I == N>* = nullptr> MyScanner& tuple_impl(MyScanner& in, Tuple& var) { return in;
} template <typename Tuple, size_t I, size_t N, enable_if_t<I != N>* = nullptr> MyScanner&
tuple_impl(MyScanner& in, Tuple& var) { in >> get<I>(var); return tuple_impl<Tuple, I+1, N>(in
, var); } template <typename... Ts> MyScanner& operator>>(MyScanner& in, tuple<Ts...>& var) {
return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(in, var); }
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


#line 2 "util/fix.cpp"

#line 4 "util/fix.cpp"

template <typename F>
class FixPoint : private F {
 public:
  explicit constexpr FixPoint(F&& f) : F(forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F> decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}
#line 5 "graph/strongly-connected-components.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

