#pragma once

#include "template.cpp"
#include "util/mapping.cpp"

template <typename T = Mapping, typename Combine = typename T::Combine>
class Doubling {
 private:
  vector<T> data;
  const T base;
  const T unit;
  const Combine combine;

 public:
  Doubling(T base_ = {}, T unit_ = {}, Combine combine_ = {})
      : data({base_}), base(base_), unit(unit_), combine(combine_) {}

 private:
  void prepare(ll n) {
    if (n <= 1) return;
    int need = 64 - __builtin_clz(n-1);
    rep(need - data.size()) data.push_back(combine(data.back(), data.back()));
  }

 public:
  T pow(ll exp) {
    prepare(exp);
    T res = unit;
    int i = 0;
    for (; exp; exp >>= 1, i++)
      if (exp & 1) res = combine(res, data[i]);
    return res;
  }

  static T pow(T base, ll exp, T unit = {}, Combine combine = {}) {
    T res = unit;
    for (; exp; exp >>= 1, base = combine(base, base))
      if (exp & 1) res = combine(res, base);
    return res;
  }
};
