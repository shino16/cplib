#ifdef LOCAL
#pragma GCC optimize ("O0")
#else
#pragma GCC optimize ("O3")
#endif

#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VVVI = vector<vector<vector<int>>>;
using VLL = vector<ll>;
using VVLL = vector<vector<ll>>;
using VVVLL = vector<vector<vector<ll>>>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using PII = pair<int, int>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1e9 + 7;
const int MOD = INF;
const ll INF_LL = 1e18 + 7;

#define __overload3(_1, _2, _3, name,...) name
#define rep(...) __overload3(__VA_ARGS__, repFromUntil, repUntil, repeat)(__VA_ARGS__)
#define repeat(times) repFromUntil(__name, 0, times)
#define repUntil(name, times) repFromUntil(name, 0, times)
#define repFromUntil(name, from, until) for (int name = from, name##__until = (until); name < name##__until; name++)
#define repFromTo(name, from, to) repFromUntil(name, from, to + 1)
#define repr(...) __overload3(__VA_ARGS__, reprFromUntil, reprUntil, repeat)(__VA_ARGS__)
#define reprUntil(name, times) reprFromUntil(name, 0, times)
#define reprFromUntil(name, from, until) for (int name = until - 1, name##__from = (from); name >= name##__from; name--)
#define reprFromTo(name, from, to) reprFromUntil(name, from, to + 1)

#define EXIT(out) do { OUT(out); exit(0); } while (false)

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define _1 first
#define _2 second

#define debug(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";debugos<<(v)<<newl;} while (0)
#define debugv(v) do {debugos << "L" << __LINE__ << " " << #v << " > ";for(auto e:(v)){debugos<<e<<" ";}debugos<<newl;} while (0)
#define debuga(m,w) do {debugos << "L" << __LINE__ << " " << #m << " > ";for(int x=0;x<(w);x++){debugos<<(m)[x]<<" ";}debugos<<newl;} while (0)
#define debugaa(m,h,w) do {debugos << "L" << __LINE__ << " " << #m << " > \n";for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){debugos<<(m)[y][x]<<" ";}debugos<<newl;}} while (0)

#define newl "\n"
constexpr int dr[] = {1,-1,0,0};
constexpr int dc[] = {0,0,1,-1};

bool inside(int r, int c, int H, int W) {
  return 0 <= r and r < H and 0 <= c and c < W;
}

template <typename T> bool chmin(T& var, T x) {
  if (var > x) {
    var = x;
    return true;
  } else return false;
}
template <typename T> bool chmax(T& var, T x) {
  if (var < x) {
    var = x;
    return true;
  } else return false;
}

template <typename T> T divceil(T m, T d) {
  return (m+d-1)/d;
}

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

template<typename T>
vector<T> make_v(size_t a, T b){return vector<T>(a, b);}

template<typename... Ts>
auto make_v(size_t a, Ts... ts){
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

class DebugPrint {
public:
  template <typename T>
  DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
    return *this;
  }
} debugos;

class MyScanner {
public:
  template <typename T> void input_integer(T& var) {
    var = 0; T sign = 1;
    int cc = getchar();
    for (; cc<'0' || '9'<cc; cc = getchar())
      if (cc == '-') sign = -1;
    for (; '0' <= cc && cc <= '9'; cc = getchar())
      var = (var << 3) + (var << 1) + cc - '0';
    var = var * sign;
  }
  int c() { char c; while (c = getchar(), c == ' ' or c == '\n'); return c; }
  MyScanner& operator>>(char& var) { var = c(); return *this; }
  MyScanner& operator>>(int& var) { input_integer<int>(var); return *this; }
  MyScanner& operator>>(ll& var) { input_integer<ll>(var); return *this; }
  MyScanner& operator>>(string& var) {
    int cc = getchar();
    for (; !isvisiblechar(cc); cc = getchar());
    for (; isvisiblechar(cc); cc = getchar())
      var.push_back(cc);
    return *this;
  }
  template <typename T, typename U>
  MyScanner& operator>>(pair<T, U>& var) {
    return *this >> var.first >> var.second;
  }
  template <typename... Ts>
  MyScanner& operator>>(tuple<Ts...>& var) {
    return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I == N>* = nullptr>
  MyScanner& tuple_impl(Tuple& var) {
    return *this;
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I != N>* = nullptr>
  MyScanner& tuple_impl(Tuple& var) {
    *this >> get<I>(var);
    return tuple_impl<Tuple, I+1, N>(var);
  }
  template <typename T>
  operator T() {
    T x;
    *this >> x;
    return x;
  }
  template <typename T>
  void operator()(T &t) {
    *this >> t;
  }
  template <typename T, typename... Ts>
  void operator()(T &t, Ts &...ts) {
    *this >> t;
    this->operator()(ts...);
  }
  template <typename Iter>
  void iter(Iter first, Iter last) {
    while (first != last) *this >> *first, first++;
  }
  VI vi(int n) {
    VI res(n);
    iter(all(res));
    return res;
  }
  VLL vll(int n) {
    VLL res(n);
    iter(all(res));
    return res;
  }
  VVI vvi(int h, int w) {
    VVI res(h);
    rep(i, h) res[i] = this->vi(w);
    return res;
  }
  template <typename T>
  vector<T> v(int n) {
    vector<T> res(n);
    iter(all(res));
    return res;
  }
private:
  int isvisiblechar(int c) {
    return 0x21 <= c && c <= 0x7E;
  }
} IN;

class MyPrinter {
public:
  template <typename T>
  void output_integer(T var) {
    if (var == 0) { putchar('0'); return; }
    if (var < 0)
      putchar('-'),
      var = -var;
    char stack[32]; int stack_p = 0;
    while (var)
      stack[stack_p++] = '0' + (var % 10),
      var /= 10;
    while (stack_p)
      putchar(stack[--stack_p]);
  }
  MyPrinter& operator<<(char c) { putchar(c); return *this; }
  template <typename T> MyPrinter& operator<<(T var) { output_integer<T>(var); return *this; }
  MyPrinter& operator<<(char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const char* str_p) { while (*str_p) putchar(*(str_p++)); return *this; }
  MyPrinter& operator<<(const string& str) {
    const char* p = str.c_str();
    const char* l = p + str.size();
    while (p < l) putchar(*p++);
    return *this;
  }
  // MyPrinter& operator<<(const modint& var) { output_integer<ll>(var.value); return *this; }
  template <typename T>
  void operator()(T x) {
    *this << x << newl;
  }
  template <typename T, typename... Ts>
  void operator()(T x, Ts ...xs) {
    *this << x << " ";
    this->operator()(xs...);
  }
  template <typename T, typename U>
  MyPrinter& operator<<(pair<T, U>& var) {
    return *this << var.first << " " << var.second;
  }
  template <typename... Ts>
  MyPrinter& operator<<(tuple<Ts...>& var) {
    return tuple_impl<tuple<Ts...>, 0, sizeof...(Ts)>(var);
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I == N>* = nullptr>
  MyPrinter& tuple_impl(Tuple& var) {
    return *this;
  }
  template <typename Tuple, size_t I, size_t N,
            enable_if_t<I != N>* = nullptr>
  MyPrinter& tuple_impl(Tuple& var) {
    *this << get<I>(var) << " ";
    return tuple_impl<Tuple, I+1, N>(var);
  }
  template <typename Iter>
  void iter(Iter s, Iter t) {
    if (s == t) *this << "\n";
    else {
      for (; s != t; s++) {
        *this << *s << " \n"[next(s, 1) == t];
      }
    }
  }
  template <typename Range>
  void range(const Range& r) {
    iter(begin(r), end(r));
  }
} OUT;


template <typename T, typename U, typename Cmb, typename ECmb, typename Upd>
struct lazy_segtree {
  const int n;
  const T unit;
  const U eunit;
  const Cmb cmb;
  const ECmb ecmb;
  const Upd upd;
  vector<T> data, lazy;
  const int h;
  // eunit need not be a unit
  segtree(int n, T unit = T(), U eunit = U(), Cmb cmb = Cmb(),
          ECmb ecmb = ECmb(), Upd upd = Upd())
      : n(n), unit(unit), eunit(eunit), cmb(cmb), ecmb(ecmb), upd(upd),
        data(n<<1, unit), lazy(n, eunit), h(32 - __builtin_clz(n)) {
    build();
  }
  // eunit need not be a unit
  template <typename Iter>
  segtree(Iter first, Iter last, int n,
          T unit = T(), Cmb cmb = Cmb(),
          ECmb ecmb = ECmb(), Upd upd = Upd())
      : n(n), unit(unit), eunit(eunit), cmb(cmb), ecmb(ecmb), upd(upd),
        data(n<<1), lazy(n, eunit), h(32 - __builtin_clz(n)) {
    assign(first, last);
  }
  void apply(int p, U e, int sz) {
    if (e == eunit) return;
    data[p] = upd(data[p], e, sz);
    if (p < n) {
      if (lazy[p] == eunit) lazy[p] = e;
      else lazy[p] = ecmb(lazy[p], e);
    }
  }
  void pushdown(int p, int sz) {
    if (p >= n or lazy[p] == eunit) return;
    apply(p<<1, lazy[p], sz>>1);
    apply(p<<1|1, lazy[p], sz>>1);
    lazy[p] = eunit;
  }
  void pushup(int p) {
    if (p >= n) return;
    data[p] = cmb(data[p<<1], data[p<<1|1]);
    if (lazy[p] != eunit) data[p] = ecmb(data[p], lazy[p]);
  }
  void flush(int l, r) {
    int s = h, k = 1 << h;
    for (l += n, r += n-1; s > 0; s--, k >>= 1)
      for (int p = l >> s; p <= r >> s; p++)
        pushdown(p, k);
  }
  void build(int l = 0, int r = n) {
    int k = 2;
    for (l += n, r += n-1; l < r; k <<= 1) {
      l >>= 1, r >>= 1;
      for (int p = l; p <= r; p++)
        pushup(p, k);
    }
  }
  template <typename Iter>
  void assign(Iter first, Iter last) {
    copy(first, last, data.begin()+n);
    build();
  }
  void modify(int l, int r, U e) {
    if (e == unit) return;
    flush(l, l+1); flush(r-1, r);
    int l0 = l, r0 = r, k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (l&1) apply(l++, e, k);
      if (r&1) apply(--r, e, k);
    }
    build(l0, l0+1);
    build(r0-1, r0);
  }
  T query(int l, int r) {
    T resl = unit, resr = unit;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = cmb(resl, data[l++]);
      if (r&1) resr = cmb(data[--r], resr);
    }
    return cmb(resl, resr);
  }
};