#pragma once

#include "template.cpp"

class BIT {
 public:
  const int n;

 private:
  vector<ll> data;

 public:
  BIT(int n_ = 0) : n(n_), data(n_ + 1) {}
  template <typename Iter>
  BIT(Iter first, Iter last) : n(distance(first, last)) {
    data = vector<ll>(n + 1);
    copy(first, last, data.begin() + 1);
    auto zeroix = data.begin() + 1;
    rep(i, n) {
      int j = i | (i+1);
      if (j < n) zeroix[j] += zeroix[i];
    }
  }
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) { return sum(r) - sum(l); }
  void clear() { fill(all(data), 0); }
  void assign(int p, ll v) { add(p, v - sum(p, p + 1)); }
  bool chmax(int p, ll v) {
    if (sum(p, p + 1) < v) {
      assign(p, v);
      return true;
    } else
      return false;
  }
  // min i s.t. sum over [0, i) >= v -- or n+1 if failed
  // requires data[i] >= 0 for any i
  int lower_bound(ll v) {
    if (v <= 0) return 0;
    int l = 0;
    for (int k = 1 << (32 - __builtin_clz(n) - 1); k; k >>= 1)
      if (l + k <= n and data[l + k] < v) v -= data[l += k];
    return l + 1;
  }
  // min i s.t. sum over [0, i) > v -- or n+1 if failed
  // requires data[i] >= 0 for any i
  int upper_bound(ll v) { return lower_bound(v + 1); }
};
