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


# :heavy_check_mark: string/hash_monoid.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/hash_monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:43:23+09:00




## Depends on

* :heavy_check_mark: <a href="../data-structure/lazy_segtree.cpp.html">data-structure/lazy_segtree.cpp</a>
* :heavy_check_mark: <a href="../data-structure/segtree.cpp.html">data-structure/segtree.cpp</a>
* :heavy_check_mark: <a href="../util/function_objects.cpp.html">util/function_objects.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/0355.test.cpp.html">verify/aoj/0355.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "data-structure/segtree.cpp"
#include "data-structure/lazy_segtree.cpp"

namespace hash_monoid {

using namespace rolling_hash;

vector<ull> sum_pows{1};

void prepare_sum_pows(size_t sz) {
  prepare_pows(sz);
  rep(i, sum_pows.size() - 1, sz - 1) {
    sum_pows.push_back(mod(sum_pows[i] + pows[i + 1]));
  }
}

// monoid
struct Hash {
  ull value;
  int length;

  Hash() : value(0), length(0) {}  // unit
  Hash(ull _value, int _length) : value(_value), length(_length) {}
  Hash(char c, int _length = 1)
      : value(calc_hash(c, _length)), length(_length) {}

 private:
  ull calc_hash(char c, int _length) {
    prepare_sum_pows(_length);
    return mod(mul(sum_pows[_length - 1], c));
  }

 public:
  operator ull() { return value; }
  bool operator==(const Hash &rhs) {
    return value == rhs.value && length == rhs.length;
  }
  bool operator!=(const Hash &rhs) {
    return value == rhs.value && length == rhs.length;
  }
};

struct mergeT {
  Hash operator()(const Hash &lhs, const Hash &rhs) const {
    prepare_pows(rhs.length + 1);
    return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),
                lhs.length + rhs.length);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct updT {
  Hash operator()(const Hash &lhs, char c, int k = 1) const {
    return Hash(c, k);
  }
};
#pragma GCC diagnostic pop

}  // namespace hash_monoid

using HashSegTree =
    SegmentTree<hash_monoid::Hash, hash_monoid::mergeT, hash_monoid::updT>;
using LazyHashSegTree =
    LazySegmentTree<hash_monoid::Hash, char, hash_monoid::mergeT, assignT,
                    hash_monoid::updT>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/hash_monoid.cpp"

#line 2 "data-structure/segtree.cpp"

#line 2 "util/function_objects.cpp"

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
  T operator()(T a, T b, int k) const { return a + b * k; }
};
#line 4 "data-structure/segtree.cpp"

#pragma GCC diagnostic push
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
#pragma GCC diagnostic pop
#line 2 "data-structure/lazy_segtree.cpp"

#line 4 "data-structure/lazy_segtree.cpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename U, typename Merge, typename EMerge, typename Upd>
struct LazySegmentTree {
 private:
  const size_t n, h;
  const T unit;
  const U eunit;
  const Merge merge;
  const EMerge emerge;
  const Upd upd;
  vector<T> data;
  vector<U> lazy;

 public:
  LazySegmentTree(size_t n = 0, T unit = T(), U eunit = U(),
                  Merge merge = Merge(), EMerge emerge = EMerge(),
                  Upd upd = Upd())
      : n(n), h(32 - __builtin_clz(n)), unit(unit), eunit(eunit), merge(merge),
        emerge(emerge), upd(upd), data(n << 1, unit), lazy(n, eunit) {
    build(0, n);
  }

  template <typename Iter,
            enable_if_t<is_same_v<typename Iter::value_type, T>>* = nullptr>
  LazySegmentTree(Iter first, Iter last, size_t n, T unit = T(), U eunit = U(),
                  Merge merge = Merge(), EMerge emerge = EMerge(),
                  Upd upd = Upd())
      : n(n), h(32 - __builtin_clz(n)), unit(unit), eunit(eunit), merge(merge),
        emerge(emerge), upd(upd), data(n << 1, unit), lazy(n, eunit) {
    assign(first, last);
  }

  template <typename Iter,
            enable_if_t<!is_same_v<typename Iter::value_type, T>>* = nullptr>
  [[deprecated]] LazySegmentTree(Iter first, Iter last, size_t n, T unit = T(),
                                 U eunit = U(), Merge merge = Merge(),
                                 EMerge emerge = EMerge(), Upd upd = Upd())
      : n(n), h(32 - __builtin_clz(n)), unit(unit), eunit(eunit), merge(merge),
        emerge(emerge), upd(upd), data(n << 1, unit), lazy(n, eunit) {
    assign(first, last);
  }

  template <typename Iter>
  LazySegmentTree(Iter first, Iter last, T unit = T(), U eunit = U(),
                  Merge merge = Merge(), EMerge emerge = EMerge(),
                  Upd upd = Upd())
      : LazySegmentTree(first, last, distance(first, last), unit, eunit, merge,
                        emerge, upd) {}

 private:
  void apply(int p, U e, int sz) {
    if (e == eunit) return;
    data[p] = upd(data[p], e, sz);
    if (p < n) {
      if (lazy[p] == eunit) lazy[p] = e;
      else lazy[p] = emerge(lazy[p], e);
    }
  }

  void pushdown(int p, int sz) {
    if (p >= n or lazy[p] == eunit) return;
    apply(p << 1, lazy[p], sz >> 1);
    apply(p << 1 | 1, lazy[p], sz >> 1);
    lazy[p] = eunit;
  }

  void pushup(int p, int sz) {
    if (p >= n) return;
    data[p] = merge(data[p << 1], data[p << 1 | 1]);
    if (lazy[p] != eunit) data[p] = upd(data[p], lazy[p], sz);
  }

  void flush(int l, int r) {
    int s = h, k = 1 << h;
    for (l += n, r += n - 1; s > 0; s--, k >>= 1)
      for (int p = l >> s; p <= r >> s; p++)
        pushdown(p, k);
  }

  void build(int l, int r) {
    int sz = 2;
    for (l += n, r += n - 1; l > 1; sz <<= 1) {
      l >>= 1, r >>= 1;
      for (int p = l; p <= r; p++) pushup(p, sz);
    }
  }

  template <typename Iter>
  void assign(Iter first, Iter last) {
    copy(first, last, data.begin() + n);
    build(0, n);
  }

 public:
  void modify(int l, int r, U e) {
    if (e == eunit) return;
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
      if (l & 1) resl = merge(resl, data[l++]);
      if (r & 1) resr = merge(data[--r], resr);
    }
    return merge(resl, resr);
  }
};
#pragma GCC diagnostic pop
#line 5 "string/hash_monoid.cpp"

namespace hash_monoid {

using namespace rolling_hash;

vector<ull> sum_pows{1};

void prepare_sum_pows(size_t sz) {
  prepare_pows(sz);
  rep(i, sum_pows.size() - 1, sz - 1) {
    sum_pows.push_back(mod(sum_pows[i] + pows[i + 1]));
  }
}

// monoid
struct Hash {
  ull value;
  int length;

  Hash() : value(0), length(0) {}  // unit
  Hash(ull _value, int _length) : value(_value), length(_length) {}
  Hash(char c, int _length = 1)
      : value(calc_hash(c, _length)), length(_length) {}

 private:
  ull calc_hash(char c, int _length) {
    prepare_sum_pows(_length);
    return mod(mul(sum_pows[_length - 1], c));
  }

 public:
  operator ull() { return value; }
  bool operator==(const Hash &rhs) {
    return value == rhs.value && length == rhs.length;
  }
  bool operator!=(const Hash &rhs) {
    return value == rhs.value && length == rhs.length;
  }
};

struct mergeT {
  Hash operator()(const Hash &lhs, const Hash &rhs) const {
    prepare_pows(rhs.length + 1);
    return Hash(mod(mul(lhs.value, pows[rhs.length]) + rhs.value),
                lhs.length + rhs.length);
  }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
struct updT {
  Hash operator()(const Hash &lhs, char c, int k = 1) const {
    return Hash(c, k);
  }
};
#pragma GCC diagnostic pop

}  // namespace hash_monoid

using HashSegTree =
    SegmentTree<hash_monoid::Hash, hash_monoid::mergeT, hash_monoid::updT>;
using LazyHashSegTree =
    LazySegmentTree<hash_monoid::Hash, char, hash_monoid::mergeT, assignT,
                    hash_monoid::updT>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

