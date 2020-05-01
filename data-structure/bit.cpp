#pragma once

#include "template.cpp"

class BIT {
 public:
  const int n;

 private:
  vector<ll> data;

 public:
  BIT(int _n = 0) : n(_n), data(_n + 1) {}
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
  void assign(int p, ll v) { add(p, v - sum(p, p + 1)); }
  bool chmax(int p, ll v) {
    if (sum(p, p + 1) < v) {
      assign(p, v);
      return true;
    } else
      return false;
  }
  // min i s.t. sum over [0, i] >= v
  // requires data[i] >= 0 for any i
  int lower_bound(ll v) {
    if (v <= 0) return 0;
    int l = 0;
    for (int k = 1 << (32 - __builtin_clz(n) - 1); k; k >>= 1)
      if (l + k <= n and data[l + k] < v) v -= data[l += k];
    return l;
  }
  // min i s.t. sum over [0, i] > v
  // requires data[i] >= 0 for any i
  int upper_bound(ll v) { return lower_bound(v + 1); }
};
