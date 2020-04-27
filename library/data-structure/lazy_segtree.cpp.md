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


# :warning: data-structure/lazy_segtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/lazy_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

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
#pragma GCC diagnostic warning "-Wshadow"

#pragma GCC diagnostic ignored "-Wunused-parameter"
struct minT {
  template <typename T>
  T operator()(T a, T b) const { return min(a, b); }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const { return max(a, b); }
};

struct assignT {
  template <typename T>
  T operator()(T a, T b, int k = 0) const { return b; }
};
#pragma GCC diagnostic ignored "-Wunused-parameter"

struct plusT {
  template <typename T>
  T operator()(T a, T b, int k) const { return a + b * k; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/lazy_segtree.cpp"

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
#pragma GCC diagnostic warning "-Wshadow"

#pragma GCC diagnostic ignored "-Wunused-parameter"
struct minT {
  template <typename T>
  T operator()(T a, T b) const { return min(a, b); }
};

struct maxT {
  template <typename T>
  T operator()(T a, T b) const { return max(a, b); }
};

struct assignT {
  template <typename T>
  T operator()(T a, T b, int k = 0) const { return b; }
};
#pragma GCC diagnostic ignored "-Wunused-parameter"

struct plusT {
  template <typename T>
  T operator()(T a, T b, int k) const { return a + b * k; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

