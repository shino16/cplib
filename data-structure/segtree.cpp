#pragma once

#include "template.cpp"
#include "util/function-objects.cpp"

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
