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
