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


# :warning: data-structure/segtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

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
            enable_if_t<is_same_v<typename Iter::value_type, T>>* = nullptr>
  SegmentTree(Iter first, Iter last, size_t n, T unit = T(),
              Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter,
            enable_if_t<!is_same_v<typename Iter::value_type, T>>* = nullptr>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
            enable_if_t<is_same_v<typename Iter::value_type, T>>* = nullptr>
  SegmentTree(Iter first, Iter last, size_t n, T unit = T(),
              Merge merge = Merge(), Upd upd = Upd())
      : n(n), unit(unit), merge(merge), upd(upd), data(n << 1) {
    copy(first, last, data.begin() + n);
    build();
  }

  template <typename Iter,
            enable_if_t<!is_same_v<typename Iter::value_type, T>>* = nullptr>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

