#pragma once

#include "template.cpp"
#include "util/function-objects.cpp"

template <typename T, typename F>
class DisjointSparseTable {
 private:
  const int n, h;
  vector<vector<T>> table;
  const T unit;
  const F f;

 public:
  DisjointSparseTable() {}
  template <typename Iter>
  DisjointSparseTable(Iter first, Iter last, T unit_, F f_ = F())
      : n(distance(first, last)),
        h(32 - __builtin_clz(n)),
        table(h, vector<T>(n)),
        unit(unit_),
        f(f_) {
    move(first, last, table[0].begin());
    rep(s, 1, h) rep(k, (n + (1 << (s + 1)) - 1) >> (s + 1)) {
      int l = k << (s + 1);
      int m = min(n, l + (1 << s));
      int r = min(n, m + (1 << s));
      table[s][m - 1] = table[0][m - 1];
      repr(i, l, m - 1) table[s][i] = f(table[0][i], table[s][i + 1]);
      if (m != n) {
        table[s][m] = table[0][m];
        rep(i, m + 1, r) table[s][i] = f(table[s][i - 1], table[0][i]);
      }
    }
  }

 public:
  T fold(int l, int r) {
    r--;
    if (l > r) return unit;
    if (l == r) return table[0][l];
    int s = 32 - __builtin_clz(l ^ r) - 1;
    return f(table[s][l], table[s][r]);
  }
};

#ifdef __cpp_deduction_guides
template <typename Iter, typename F>
DisjointSparseTable(Iter first, Iter last, typename Iter::value::type unit_,
                    F f_ = F())
    ->DisjointSparseTable<typename Iter::value_type, F>;
#endif
