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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: verify/aoj/GRL_1_A_fh.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#74053cc99b0559ce9aeee19793c084e1">verify/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/verify/aoj/GRL_1_A_fh.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 10:44:16+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/fibonacci_heap.cpp.html">data-structure/fibonacci_heap.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/dijkstra_fib_heap.cpp.html">graph/dijkstra_fib_heap.cpp</a>
* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include "template.cpp"
#include "data-structure/fibonacci_heap.cpp"
#include "graph/dijkstra_fib_heap.cpp"


int main() {
  int n = IN, m = IN, r = IN;
  Graph graph(n);
  rep(m) {
    int u = IN, v = IN, d = IN;
    graph[u].emplace_back(v, d);
  }
  auto d = dijkstra(graph, r);
  rep(i, n) OUT(d[i] >= INF ? "INF" : to_string(d[i]));
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verify/aoj/GRL_1_A_fh.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#line 1 "template.cpp"

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
#pragma GCC diagnostic warning "-Wmisleading-indentation"
#line 1 "data-structure/fibonacci_heap.cpp"

// credit to: rsk0315 (https://atcoder.jp/users/rsk0315)
// this implementation is from https://atcoder.jp/contests/arc064/submissions/8197391

#include <list>
#include <memory>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

namespace bit {
template <typename Tp>
int log2p1(Tp n) {
  if (n == 0) return 0;
  return (8 * sizeof(long long)) - __builtin_clzll(n);
}
}  // bit::

template <typename Key, typename Tp, typename Compare = std::less<>>
class fibonacci_heap {
public:
  using size_type = size_t;
  using key_type = Key;
  using mapped_type = Tp;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = value_type const&;
  using key_compare = Compare;
  class node_handle;

private:
  class node;
  using pointer = std::shared_ptr<node>;

  class node {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;

  private:
    pointer M_parent{nullptr};
    pointer M_child{nullptr};
    pointer M_left{nullptr};
    pointer M_right{nullptr};
    bool M_damaged = false;
    size_type M_order = 0;
    value_type M_value;  // {priority, element}

  public:
    node() = default;
    node(node const&) = default;
    node(node&&) = default;
    node& operator =(node const&) = default;
    node& operator =(node&&) = default;

    node(key_type const& key, mapped_type const& mapped):
      M_value(key, mapped) {}
  };

  static void S_add_child(pointer parent, pointer child) {
    ++parent->M_order;
    child->M_parent = parent;
    if (!parent->M_child) {
      parent->M_child = child;
      child->M_left = child->M_right = nullptr;
    } else if (!parent->M_child->M_left) {
      parent->M_child->M_left = parent->M_child->M_right = child;
      child->M_left = child->M_right = parent->M_child;
    } else {
      child->M_left = parent->M_child->M_left;
      child->M_right = parent->M_child;
      parent->M_child->M_left->M_right = child;
      parent->M_child->M_left = child;
    }
  }

  static bool S_detach_child(pointer parent, pointer child) {
    // returns true if the resulting heap is valid, false otherwise
    bool res = !parent->M_damaged;
    if (parent->M_parent) parent->M_damaged = true;
    --parent->M_order;

    if (parent->M_child == child) parent->M_child = child->M_right;
    child->M_parent = nullptr;
    child->M_damaged = false;

    if (child->M_left) {
      if (child->M_left == child->M_right) {
        child->M_left->M_right = child->M_right->M_left = nullptr;
      } else {
        child->M_left->M_right = child->M_right;
        child->M_right->M_left = child->M_left;
      }
      child->M_left = child->M_right = nullptr;
    }
    return res;
  }

public:
  class node_handle {
    friend fibonacci_heap;

  public:
    using size_type = size_t;
    using key_type = Key;
    using mapped_type = Tp;
    using value_type = std::pair<key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = value_type const&;
    using key_compare = Compare;
    using pointer = std::weak_ptr<node>;

  private:
    pointer M_node;

  public:
    node_handle() = default;
    node_handle(pointer node): M_node(node) {}
    const_reference operator *() const { return (*M_node)->M_value; }
    bool expired() const { return M_node.expired(); }
  };

private:
  size_type M_size = 0;
  std::list<pointer> M_roots;  // list for pop()
  pointer M_top;  // pointer (not iterator) for prioritize()
  key_compare M_comp = key_compare();

  static size_type S_num_nodes(pointer cur) {
    pointer child = cur->M_child;
    if (!child) return 1;
    size_type res = 1;
    do {
      res += S_num_nodes(child);
      child = child->M_right;
    } while (child && child != cur->M_child);
    return res;
  }

  void M_coleasce() {
    if (M_size == 0) {
      M_roots.clear();
      M_top = nullptr;
      return;
    }

    size_type size = 0;
    for (auto r: M_roots) size += 1_zu << r->M_order;
    std::vector<pointer> roots(bit::log2p1(size));

    for (auto r: M_roots) {
      size_type i = r->M_order;
      while (roots[i]) {
        if (M_comp(r->M_value.first, roots[i]->M_value.first))
          std::swap(r, roots[i]);

        S_add_child(r, roots[i]);
        roots[i] = nullptr;
        ++i;
      }
      roots[i] = r;
    }
    M_roots.clear();

    for (auto r: roots) if (r) M_roots.push_back(r);
    M_top = *M_roots.begin();
    for (auto p: M_roots)
      if (M_comp(M_top->M_value.first, p->M_value.first)) M_top = p;
  }

public:
  fibonacci_heap() = default;
  fibonacci_heap(fibonacci_heap const&) = delete;
  fibonacci_heap(fibonacci_heap&&) = default;
  fibonacci_heap& operator =(fibonacci_heap const&) = delete;
  fibonacci_heap& operator =(fibonacci_heap&&) = default;

  template <typename InputIt>
  fibonacci_heap(InputIt first, InputIt last) { assign(first, last); }
  fibonacci_heap(std::initializer_list<value_type> il) { assign(il); }

  size_type size() const noexcept { return M_size; }
  bool empty() const noexcept { return M_size == 0; }

  const_reference const& top() const { return M_top->M_value; }
  void pop() {
    pointer root = M_top;
    for (auto it = M_roots.begin(); it != M_roots.end(); ++it) {
      if (*it == M_top) {
        M_roots.erase(it);
        break;
      }
    }
    if (root->M_child) {
      pointer cur = root->M_child;
      do {
        pointer tmp = cur->M_right;
        cur->M_left = cur->M_right = cur->M_parent = nullptr;
        cur->M_damaged = false;
        M_roots.push_back(cur);
        cur = tmp;
      } while (cur && cur != root->M_child);
      root->M_child = nullptr;
    }
    --M_size;
    M_coleasce();
  }

  node_handle push(key_type const& key, mapped_type const& mapped) {
    pointer newnode = std::make_shared<node>(key, mapped);
    newnode->M_left = newnode->M_right = nullptr;
    M_roots.push_back(newnode);
    if (M_size == 0 || M_comp(M_top->M_value.first, key)) M_top = newnode;
    ++M_size;
    return node_handle(newnode);
  }

  void meld(fibonacci_heap& other) {
    M_size += other.M_size;
    other.M_size = 0;

    M_roots.splice(M_roots.end(), other.M_roots);
    if (M_comp(M_top->M_value.first, other.M_top->M_value.first))
      M_top = other.M_top;
  }

  void prioritize(node_handle& nh, key_type const& key) {
    pointer cur(nh.M_node);
    // assert(M_comp(cur->M_value.first, key));
    cur->M_value.first = key;
    if (M_comp(M_top->M_value.first, key)) M_top = cur;
    if (!cur->M_parent || !M_comp(cur->M_parent->M_value.first, key)) return;

    bool more_cut = true;
    while (more_cut) {
      pointer parent = cur->M_parent;
      more_cut = !S_detach_child(parent, cur);
      M_roots.push_back(cur);
      cur = parent;
    }
  }
};

#line 1 "graph/dijkstra_fib_heap.cpp"

vector<ll> dijkstra(const Graph& graph, int start) {
  fibonacci_heap<ll, int, greater<>> q;
  vector<ll> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      ll d2 = d + e.cost;
      if (chmin(dist[e.to], d2)) {
        if (handles[e.to].expired()) handles[e.to] = q.push(d2, e.to);
        else q.prioritize(handles[e.to], d2);
      }
    }
  }
  return dist;
}
#line 6 "verify/aoj/GRL_1_A_fh.test.cpp"


int main() {
  int n = IN, m = IN, r = IN;
  Graph graph(n);
  rep(m) {
    int u = IN, v = IN, d = IN;
    graph[u].emplace_back(v, d);
  }
  auto d = dijkstra(graph, r);
  rep(i, n) OUT(d[i] >= INF ? "INF" : to_string(d[i]));
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

