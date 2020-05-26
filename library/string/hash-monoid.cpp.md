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


# :x: string/hash-monoid.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/hash-monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-27 03:08:41+09:00




## Depends on

* :x: <a href="../data-structure/lazy-segtree.cpp.html">data-structure/lazy-segtree.cpp</a>
* :question: <a href="../data-structure/segtree.cpp.html">data-structure/segtree.cpp</a>
* :x: <a href="rolling-hash.cpp.html">string/rolling-hash.cpp</a>
* :question: <a href="../template.cpp.html">template.cpp</a>
* :question: <a href="../util/function-objects.cpp.html">util/function-objects.cpp</a>


## Verified with

* :x: <a href="../../verify/verify/aoj/0355.test.cpp.html">verify/aoj/0355.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "string/rolling-hash.cpp"
#include "data-structure/segtree.cpp"
#include "data-structure/lazy-segtree.cpp"

namespace hash_monoid {

using namespace rolling_hash;

struct mergeT {
  Hash operator()(const Hash& lhs, const Hash& rhs) const {
    prepare_pows(rhs.length + 1);
    return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),
                lhs.length + rhs.length);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct updT {
  Hash operator()(const Hash& lhs, char c, int k = 1) const {
    return Hash(c, k);
  }
};
#pragma GCC diagnostic pop

}  // namespace hash_monoid

using HashSegTree =
    SegmentTree<rolling_hash::Hash, hash_monoid::mergeT, hash_monoid::updT>;
using LazyHashSegTree =
    LazySegmentTree<rolling_hash::Hash, char, hash_monoid::mergeT, assignT,
                    hash_monoid::updT>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/hash-monoid.cpp"

#line 2 "string/rolling-hash.cpp"

#include <random>
#line 2 "template.cpp"

#ifndef LOCAL
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
template <typename T, typename U> T divceil(T m, U d) { return (m + d - 1) / d; }
template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// debugging stuff
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define repi(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
class DebugPrint { public: template <typename T> DebugPrint& operator <<(const T& v) {
#ifdef LOCAL
    cerr << v;
#endif
return *this; } } debugos; template <typename T> DebugPrint& operator<<(DebugPrint& os, const
vector<T>& vec) { os << "{"; for (int i = 0; i < vec.size(); i++) os << vec[i] << (i + 1 ==
vec.size() ? "" : ", "); os << "}"; return os; } template <typename T, typename U> DebugPrint&
operator<<(DebugPrint& os, const map<T, U>& map_var) { os << "{"; repi(itr, map_var) { os << *
itr; itr++; if (itr != map_var.end()) os << ", "; itr--; } os << "}"; return os; } template <
typename T> DebugPrint& operator<<(DebugPrint& os, const set<T>& set_var) { os << "{"; repi(
itr, set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; } os << "}";
return os; } template <typename T, typename U> DebugPrint& operator<<(DebugPrint& os, const
pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; } void dump_func(
) { debugos << newl; } template <class Head, class... Tail> void dump_func(Head &&head, Tail
&&... tail) { debugos << head; if (sizeof...(Tail) > 0) { debugos << ", "; } dump_func(forward
<Tail>(tail)...); }
#ifdef LOCAL
#define dump(...) debugos << "  " << string(#__VA_ARGS__) << ": " << "[" << to_string(__LINE__) \
<< ":" << __FUNCTION__ << "]" << newl << "    ", dump_func(__VA_ARGS__)
#else
#define dump(...) ({})
#endif
#pragma GCC diagnostic pop


#line 5 "string/rolling-hash.cpp"

namespace rolling_hash {

constexpr ull mask30 = (1ULL << 30) - 1;
constexpr ull mask31 = (1ULL << 31) - 1;
constexpr ull MOD = (1ULL << 61) - 1;
random_device rd;
int base = uniform_int_distribution<ull>(0)(rd);
vector<ull> pows{1};
vector<ull> sum_pows{1};

ull mod(ull val) {
  val = (val & MOD) + (val >> 61);
  return val >= MOD ? val - MOD : val;
}

ull mul(ull l, ull r) {
  ull lu = l >> 31, ld = l & mask31;
  ull ru = r >> 31, rd = r & mask31;
  ull middle = ld * ru + lu * rd;
  return ((lu * ru) << 1) + ld * rd + ((middle & mask30) << 31) +
         (middle >> 30);
}

ull mul(ull l, int r) {
  ull lu = l >> 31, ld = l & mask31;
  ull middle = lu * r;
  return ld * r + ((middle & mask30) << 31) + (middle >> 30);
}

void prepare_pows(size_t sz) {
  rep(i, pows.size() - 1, sz - 1) pows.push_back(mod(mul(pows[i], base)));
}

void prepare_sum_pows(size_t sz) {
  prepare_pows(sz);
  rep(i, sum_pows.size() - 1, sz - 1) {
    sum_pows.push_back(mod(sum_pows[i] + pows[i + 1]));
  }
}

ull calc_hash(char c, int _length) {
  prepare_sum_pows(_length);
  return mod(mul(sum_pows[_length - 1], c));
}

template <typename Iter>
ull calc_hash(Iter first, Iter last) {
  ull res = 0;
  while (first != last) res = mod(mul(res, base) + *first++);
  return res;
}

// monoid
struct Hash {
  ull value;
  int length;

  Hash() : value(0), length(0) {}  // unit
  Hash(ull _value, int _length) : value(_value), length(_length) {}
  Hash(char c, int _length = 1)
      : value(calc_hash(c, _length)), length(_length) {}
  template <typename Iter>
  Hash(Iter first, Iter last): value(calc_hash(first, last)), length(distance(first, last)) {}

 public:
  operator ull() const { return value; }
  bool operator==(const Hash& rhs) const {
    return value == rhs.value && length == rhs.length;
  }
  bool operator!=(const Hash& rhs) const {
    return value != rhs.value && length != rhs.length;
  }
  bool operator<(const Hash& rhs) const {
    return make_pair(length, value) < make_pair(rhs.length, rhs.value);
  }
};

class Calculator {
 private:
  vector<ull> hash;

 public:
  template <typename Iter>
  Calculator(Iter first, Iter last) : hash(last - first + 1) {
    prepare_pows(last - first + 1);
    rep(i, last - first) hash[i + 1] = mod(mul(hash[i], base) + first[i]);
    // assert(hash[i+1] < (1ULL << 62));
  }

 public:
  ull operator()(int l, int r) const {
    static constexpr ull large = MOD * ((1 << 2) - 1);
    return mod(hash[r] + large - mul(hash[l], pows[r - l]));
  }
  Hash get_hash(int l, int r) const {
    return Hash(operator()(l, r), r - l);
  }
};

}  // namespace rolling_hash
#line 2 "data-structure/segtree.cpp"

#line 2 "util/function-objects.cpp"

#line 4 "util/function-objects.cpp"

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct assignT {
  template <typename T>
  T operator()(T a, T b, int k = 0) const { return b; }
};
#pragma GCC diagnostic pop

struct plusT {
  template <typename T>
  T operator()(T a, T b, int k = 1) const { return a + b * k; }
};
#line 5 "data-structure/segtree.cpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Combine, typename Action>
class SegmentTree {
 private:
  const size_t n;
  const T unit;
  const Combine combine;
  const Action action;
  vector<T> data;

 public:
  SegmentTree(size_t n = 0, T unit = {}, Combine combine = {},
              Action action = {})
      : n(n), unit(unit), combine(combine), action(action), data(n << 1, unit) {
    build();
  }

  template <
      typename Iter,
      enable_if_t<is_same<typename Iter::value_type, T>::value>* = nullptr>
  SegmentTree(Iter first, Iter last, size_t n, T unit = {},
              Combine combine = {}, Action action = {})
      : n(n), unit(unit), combine(combine), action(action), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <
      typename Iter,
      enable_if_t<!is_same<typename Iter::value_type, T>::value>* = nullptr>
  [[deprecated]] SegmentTree(Iter first, Iter last, size_t n, T unit = {},
                             Combine combine = {}, Action action = {})
      : n(n), unit(unit), combine(combine), action(action), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter>
  SegmentTree(Iter first, Iter last, T unit = {}, Combine combine = {},
              Action action = {})
      : SegmentTree(first, last, distance(first, last), unit, combine, action) {
  }

 private:
  void build() { repr(i, n) data[i] = combine(data[i << 1], data[i << 1 | 1]); }

 public:
  void modify(int l, T v) {
    l += n;
    data[l] = action(data[l], v);
    for (; l > 1; l >>= 1) data[l >> 1] = combine(data[l & (~1)], data[l | 1]);
  }

  T fold(int l, int r) const {
    if (l == r) return unit;
    if (l + 1 == r) return data[l + n];
    T resl = data[l += n], resr = data[(r += n) - 1];
    for (l++, r--; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = combine(resl, data[l++]);
      if (r & 1) resr = combine(data[--r], resr);
    }
    return combine(resl, resr);
  }
  // min r s.t. fold(l, r) >= v -- or n+1 if failed
  template <typename Compare = less<T>>
  int lower_bound(T v, int l = 0, Compare comp = {}) {
    if (not comp(unit, v)) return l;
    int r = n;
    VI rootL, rootR;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) rootL.push_back(l++);
      if (r & 1) rootR.push_back(--r);
    }
    VI roots = move(rootL); roots.insert(roots.end(), rall(rootR));
    T accL = unit;
    for (int root : roots) {
      T tmpL = combine(accL, data[root]);
      if (comp(tmpL, v)) {
        accL = tmpL;
        continue;
      }
      while (root < n) {
        tmpL = combine(accL, data[root << 1]);
        if (comp(tmpL, v)) accL = tmpL, root = root << 1 | 1;
        else root = root << 1;
      }
      return root - n + 1;
    }
    return n + 1;
  }
};
#pragma GCC diagnostic pop
#line 2 "data-structure/lazy-segtree.cpp"

#line 5 "data-structure/lazy-segtree.cpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Actor, typename Combine, typename ACombine,
          typename Action>
struct LazySegmentTree {
 private:
  const size_t n, h;
  const T unit;
  const Actor aunit;
  const Combine combine;
  const ACombine acombine;
  const Action upd;
  vector<T> data;
  vector<Actor> lazy;

 public:
  LazySegmentTree(size_t n = 0, T unit = {}, Actor aunit = {},
                  Combine combine = {}, ACombine acombine = {}, Action upd = {})
      : n(n),
        h(32 - __builtin_clz(n)),
        unit(unit),
        aunit(aunit),
        combine(combine),
        acombine(acombine),
        upd(upd),
        data(n << 1, unit),
        lazy(n, aunit) {
    build(0, n);
  }

  template <
      typename Iter,
      enable_if_t<is_same<typename Iter::value_type, T>::value>* = nullptr>
  LazySegmentTree(Iter first, Iter last, size_t n, T unit = {},
                  Actor aunit = {}, Combine combine = {},
                  ACombine acombine = {}, Action upd = {})
      : n(n),
        h(32 - __builtin_clz(n)),
        unit(unit),
        aunit(aunit),
        combine(combine),
        acombine(acombine),
        upd(upd),
        data(n << 1, unit),
        lazy(n, aunit) {
    copy(first, last, data.begin() + n);
    build(0, n);
  }

  template <
      typename Iter,
      enable_if_t<!is_same<typename Iter::value_type, T>::value>* = nullptr>
  [[deprecated]] LazySegmentTree(Iter first, Iter last, size_t n, T unit = {},
                                 Actor aunit = {}, Combine combine = {},
                                 ACombine acombine = {}, Action upd = {})
      : n(n),
        h(32 - __builtin_clz(n)),
        unit(unit),
        aunit(aunit),
        combine(combine),
        acombine(acombine),
        upd(upd),
        data(n << 1, unit),
        lazy(n, aunit) {
    copy(first, last, data.begin() + n);
    build(0, n);
  }

  template <typename Iter>
  LazySegmentTree(Iter first, Iter last, T unit = {}, Actor aunit = {},
                  Combine combine = {}, ACombine acombine = {}, Action upd = {})
      : LazySegmentTree(first, last, distance(first, last), unit, aunit,
                        combine, acombine, upd) {}

 private:
  void apply(int p, Actor e, int sz) {
    if (e == aunit) return;
    data[p] = upd(data[p], e, sz);
    if (p < n) {
      if (lazy[p] == aunit)
        lazy[p] = e;
      else
        lazy[p] = acombine(lazy[p], e);
    }
  }

  void pushdown(int p, int sz) {
    if (p >= n or lazy[p] == aunit) return;
    apply(p << 1, lazy[p], sz >> 1);
    apply(p << 1 | 1, lazy[p], sz >> 1);
    lazy[p] = aunit;
  }

  void pushup(int p, int sz) {
    if (p >= n) return;
    data[p] = combine(data[p << 1], data[p << 1 | 1]);
    if (lazy[p] != aunit) data[p] = upd(data[p], lazy[p], sz);
  }

  void flush(int l, int r) {
    int s = h, k = 1 << h;
    for (l += n, r += n - 1; s > 0; s--, k >>= 1)
      for (int p = l >> s; p <= r >> s; p++) pushdown(p, k);
  }

  void build(int l, int r) {
    int sz = 2;
    for (l += n, r += n - 1; l > 1; sz <<= 1) {
      l >>= 1, r >>= 1;
      for (int p = l; p <= r; p++) pushup(p, sz);
    }
  }

 public:
  void modify(int l, int r, Actor e) {
    if (e == aunit) return;
    flush(l, l + 1);
    flush(r - 1, r);
    int l0 = l, r0 = r, k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) apply(l++, e, k);
      if (r & 1) apply(--r, e, k);
    }
    build(l0, l0 + 1);
    build(r0 - 1, r0);
  }

  T fold(int l, int r) {
    flush(l, l + 1);
    flush(r - 1, r);
    T resl = unit, resr = unit;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = combine(resl, data[l++]);
      if (r & 1) resr = combine(data[--r], resr);
    }
    return combine(resl, resr);
  }
};
#pragma GCC diagnostic pop
#line 6 "string/hash-monoid.cpp"

namespace hash_monoid {

using namespace rolling_hash;

struct mergeT {
  Hash operator()(const Hash& lhs, const Hash& rhs) const {
    prepare_pows(rhs.length + 1);
    return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),
                lhs.length + rhs.length);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct updT {
  Hash operator()(const Hash& lhs, char c, int k = 1) const {
    return Hash(c, k);
  }
};
#pragma GCC diagnostic pop

}  // namespace hash_monoid

using HashSegTree =
    SegmentTree<rolling_hash::Hash, hash_monoid::mergeT, hash_monoid::updT>;
using LazyHashSegTree =
    LazySegmentTree<rolling_hash::Hash, char, hash_monoid::mergeT, assignT,
                    hash_monoid::updT>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

