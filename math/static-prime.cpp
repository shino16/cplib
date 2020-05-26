#pragma once

#include "template.cpp"

template <size_t N>
class StaticPrime {
 private:
  bitset<N+1> prime = move(bitset<N+1>().set());

 public:
  StaticPrime() { build(); }

 private:
  void build() {
    prime[0] = prime[1] = false;
    rep(i, 2, n+1) if (prime[i]) {
      for (int j = i*2; j < n+1; j += i) prime[j] = false;
    }
  }

 public:
  bool operator()(int n) {
    return prime[n];
  }
};
