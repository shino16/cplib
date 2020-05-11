#pragma once

#include "template.cpp"
#include "util/function-objects.cpp"

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
