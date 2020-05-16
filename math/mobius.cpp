#pragma once

#include "template.cpp"
#include "math/prime.cpp"

class Mobeus {
 private:
  static vector<int> mobeus;
  static Prime prime;

 public:
  Mobeus(int n = 0) { build(n); }

  void build(int n) {
    if (mobeus.size() > n) return;
    chmax(n, 1);
    prime.build(n);
    mobeus.resize(n+1);
    fill(all(mobeus), 1);
    for (int p = 2; p < n+1; p++) if (prime(p)) {
      int val = 1;
      for (int i = p; i < n+1; i += p) mobeus[i] = -mobeus[i];
      if (p < sqrt(n+1)+1)
        for (int i = p*p; i < n+1; i += p*p) mobeus[i] = 0;
    }
  }

  int operator()(int n) {
    build(n);
    return mobeus[n];
  }
};

vector<int> Mobeus::mobeus;
Prime Mobeus::prime;
