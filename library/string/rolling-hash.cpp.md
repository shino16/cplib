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


# :heavy_check_mark: string/rolling-hash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling-hash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 23:32:59+09:00




## Depends on

* :question: <a href="../template.cpp.html">template.cpp</a>


## Required by

* :heavy_check_mark: <a href="hash-monoid.cpp.html">string/hash-monoid.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/0355.test.cpp.html">verify/aoj/0355.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "template.cpp"

namespace rolling_hash {

constexpr ull mask30 = (1ULL << 30) - 1;
constexpr ull mask31 = (1ULL << 31) - 1;
constexpr ull MOD = (1ULL << 61) - 1;
int base = rand();
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/rolling-hash.cpp"

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


#line 4 "string/rolling-hash.cpp"

namespace rolling_hash {

constexpr ull mask30 = (1ULL << 30) - 1;
constexpr ull mask31 = (1ULL << 31) - 1;
constexpr ull MOD = (1ULL << 61) - 1;
int base = rand();
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
