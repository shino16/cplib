#pragma once

#include "template.cpp"

class Mapping {
 public:
  struct Combine {
    Mapping operator()(const Mapping& lhs, const Mapping& rhs) {
      if (lhs.f.empty()) return rhs;
      if (rhs.f.empty()) return lhs;
      assert(lhs.f.size() == rhs.f.size());
      int n = lhs.f.size();
      vector<int> f(n);
      rep(x, n) {
        int y = rhs.f[x];
        f[x] = 0 <= y and y < n ? lhs.f[y] : y;
      }
      return Mapping(move(f));
    }
  };

 private:
  vector<int> f;

 public:
  Mapping() = default;
  Mapping(int n) : f(n) { iota(all(f), 0); }
  Mapping(const vector<int>& f_) : f(f_) {}
  Mapping(vector<int>&& f_) : f(move(f_)) {}

  int operator()(int x) { return f[x]; }
};

template <typename T = Mapping, typename Combine = typename T::Combine>
class Doubling {
 private:
  vector<T> data;
  const T unit;
  const Combine combine;

 public:
  Doubling(T unit_ = {}, Combine combine_ = {})
      : data({unit_}), unit(unit_), combine(combine_) {}

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
