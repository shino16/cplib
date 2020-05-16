#pragma once

#include "template.cpp"

class Prime {
 private:
  static vector<bool> prime;

 public:
  Prime(int n = 0) { build(n); }

  void build(int n) {
    if (prime.size() > n) return;
    n *= 2;
    chmax(n, 1);
    prime.resize(n+1);
    fill(all(prime), true);
    prime[0] = prime[1] = false;
    rep(i, 2, n+1) if (prime[i]) {
      for (int j = i*2; j < n+1; j += i) prime[j] = false;
    }
  }

  bool operator()(int n) {
    build(n);
    return prime[n];
  }

  static vector<int> primes(int mx) {
    Prime prime(mx);
    vector<int> res;
    rep(n, 2, mx+1) if (prime(n)) res.push_back(n);
    return res;
  }

  static bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    rep(d, 2, sqrt(n)+1) if (n % d == 0) return false;
    return true;
  }
};

vector<bool> Prime::prime;
