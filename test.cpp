#line 1 "verify/aoj/0367.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367"
// "https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0367?year=2017"

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
#line 1 "data-structure/segtree.cpp"

#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Merge, typename Upd>
class SegmentTree {
 private:
  const size_t n;
  const T unit;
  const Merge merge;
  const Upd upd;
  vector<T> data;

 public:
  SegmentTree(size_t n = 0, T unit = T(), Merge merge = Merge(),
              Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1, unit) {
    build();
  }

  template <typename Iter,
            enable_if_t<is_same<typename Iter::value_type, T>::value>* = nullptr>
  SegmentTree(Iter first, Iter last, size_t n, T unit = T(),
              Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter,
            enable_if_t<!is_same<typename Iter::value_type, T>::value>* = nullptr>
  [[deprecated]] SegmentTree(Iter first, Iter last, size_t n, T unit = T(),
                             Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter>
  SegmentTree(Iter first, Iter last, T unit = T(), Merge merge = Merge(),
              Upd upd = Upd())
      : SegmentTree(first, last, distance(first, last), unit, merge, upd) {}

 private:
  void build() { repr(i, n) data[i] = merge(data[i << 1], data[i << 1 | 1]); }

 public:
  void modify(int l, T v) {
    l += n;
    data[l] = upd(data[l], v);
    for (; l > 1; l >>= 1) data[l >> 1] = merge(data[l & (~1)], data[l | 1]);
  }

  T fold(int l, int r) const {
    if (l == r) return unit;
    if (l + 1 == r) return data[l + n];
    T resl = data[l += n], resr = data[(r += n) - 1];
    for (l++, r--; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = merge(resl, data[l++]);
      if (r & 1) resr = merge(data[--r], resr);
    }
    return merge(resl, resr);
  }
};
#pragma GCC diagnostic warning "-Wshadow"

struct minT {
  template <typename T>
  T operator()(T a, T b) const {
    return min(a, b);
  }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const {
    return max(a, b);
  }
};

#pragma GCC diagnostic ignored "-Wunused-parameter"
struct assign {
  template <typename T>
  T operator()(T a, T b) const {
    return b;
  }
};
#pragma GCC diagnostic warning "-Wunused-parameter"
#line 1 "tree/hld.cpp"

// originally written by @beet-aizu
class HLD {
 private:
  VI index, sz, par, rev;
  // last vertex in ascending heavy path
  VI nxt;

 public:
  HLD(Graph& graph)
      : index(graph.size()), sz(graph.size(), 1),
        par(graph.size(), -1), rev(graph.size()), nxt(graph.size()) {
    dfs_sz(graph, 0);
    dfs_hld(graph, 0);
  }

 private:
  void dfs_sz(Graph& graph, int v) {
    if (graph[v].size() >= 2 and graph[v][0] == par[v])
      swap(graph[v][0], graph[v][1]);
    for (auto& c : graph[v])
      if (c != par[v]) {
        par[c] = v;
        dfs_sz(graph, c);
        sz[v] += sz[c];
        if (sz[c] > sz[graph[v][0]]) swap(c, graph[v][0]);
      }
  }

  void dfs_hld(const Graph& graph, int v) {
    static int t = 0;
    index[v] = t++;
    rev[index[v]] = v;
    for (auto c : graph[v])
      if (c != par[v]) {
        nxt[c] = (c.to == graph[v][0].to ? nxt[v] : c.to);
        dfs_hld(graph, c);
      }
    assert(sz[v] == t - index[v]);
  }

 public:
  template <typename F>
  void path_vertex(int u, int v, F f) {
    while (true) {
      if (index[u] > index[v]) swap(u, v);
      // debug(u); debug(v);
      // debug(nxt[u]); debug(index[u]);
      f(max(index[nxt[v]], index[u]), index[v] + 1);
      if (nxt[u] != nxt[v])
        v = par[nxt[v]];
      else
        break;
    }
  }

  template <typename F>
  void path_edge(int u, int v, F f) {
    while (true) {
      if (index[u] > index[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(index[nxt[v]], index[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v) f(index[u] + 1, index[v] + 1);
        break;
      }
    }
  }

  template <typename F>
  void subtree_vertex(int v, F f) {
    f(index[v], index[v] + sz[v]);
  }

  template <typename F>
  void subtree_edge(int v, F f) {
    f(index[v] + 1, index[v] + sz[v]);
  }

  int lca(int u, int v) {
    while (1) {
      if (index[u] > index[v]) swap(u, v);
      if (nxt[u] == nxt[v]) return u;
      v = par[nxt[v]];
    }
  }

  int subtree_size(int v) { return sz[v]; }

  int vertex(int v) { return index[v]; }

  int parent(int v) { return par[v]; }

  int restore(int ix) { return rev[ix]; }
};
#line 1 "util/compress.cpp"

template <typename T = ll>
class Compress {
 private:
  vector<T> data;
  bool built;

 public:
  Compress() { build(); }
  template <typename Iter>
  Compress(Iter first, Iter last) : data(first, last) {
    build();
  }

 private:
  void build() {
    if (not built) {
      sort(all(data));
      data.erase(unique(all(data)), data.end());
      built = true;
    }
  }

 public:
  void insert(T v) {
    built = false;
    data.push_back(v);
  }
  template <typename... Args>
  void emplace(Args&&... args) {
    built = false;
    data.emplace_back(forward<Args>(args)...);
  }
  int size() {
    build();
    return data.size();
  }
  int operator[](T v) {
    build();
    assert(binary_search(all(data), v));
    return std::lower_bound(all(data), v) - data.begin();
  }
  T restore(int i) {
    build();
    return data[i];
  }
  int lower_bound(T v) {
    build();
    return std::lower_bound(all(data), v) - data.begin();
  }
  int upper_bound(T v) {
    build();
    return std::upper_bound(all(data), v) - data.begin();
  }
  bool count(T v) {
    build();
    return std::binary_search(all(data), v);
  }
};
#line 8 "verify/aoj/0367.test.cpp"

struct Path {
  array<int, 2> to;
  ll cost;
  Path(int u = -1, int v = -1, ll _cost = -1) : to({min(u, v), max(u, v)}), cost(_cost) {}
  bool operator==(const Path& rhs) const { return to == rhs.to; }
  bool operator<(const Path& rhs) const { return to < rhs.to; }
};

int main() {
  int n = IN, k = IN;

  Graph graph(n);
  VLL weight(n);
  Compress<Path> edges;

  rep(n - 1) {
    int a = IN, b = IN, c = IN;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    edges.emplace(a, b, c);
  }

  HLD hld(graph);

  auto merge_path = [&](const Path& a, const Path& b) {
    if (a.cost == -1) return b; else if (b.cost == -1) return a;
    auto edge_cost = [&](int u, int v) {
      ll res = weight[u] + weight[v]
               + edges.restore(edges[Path(u, v)]).cost;
      return res % k ? res : 0;
    };
    rep(i, 2) rep(j, 2)
      if (edges.count(Path(a.to[i], b.to[j])))
      // if (hld.parent(a.to[i]) == b.to[j] or a.to[i] == hld.parent(b.to[j]))
        return Path(a.to[i ^ 1], b.to[j ^ 1],
                    a.cost + b.cost + edge_cost(a.to[i], b.to[j]));
    return Path();
  };

  auto do_nothing = [](auto x, auto y) { return x; };

  vector<Path> paths(n);
  rep(i, n) paths[i] = Path(hld.restore(i), hld.restore(i), 0);

  SegmentTree<Path, decltype(merge_path), decltype(do_nothing)>
    segtree(paths.begin(), paths.end(), n, Path(), merge_path, do_nothing);

  rep(IN) {
    string cmd = IN; int x = IN, y = IN;
    if (cmd[0] == 'a') weight[x] += y, segtree.modify(hld.vertex(x), Path());
    else {
      Path r1, r2;
      int z = hld.lca(x, y);
      hld.path_vertex(x, z, [&](auto l, auto r){ r1 = merge_path(r1, segtree.fold(l, r)); });
      hld.path_edge(y, z, [&](auto l, auto r){ r2 = merge_path(r2, segtree.fold(l, r)); });
      OUT(merge_path(r1, r2).cost);
    }
  }
}
