#pragma once

#include "template.cpp"

template <typename M>
class binomial {
public:
  vector<M> fact, invfact;
  binomial(int n) : fact(n+1), invfact(n+1) {
    fact[0] = 1;
    rep(i, n) fact[i+1] = fact[i] * M(i+1);
    invfact[n] = M(1) / fact[n];
    repr(i, n) invfact[i] = invfact[i+1] * M(i+1);
  }
  M operator()(int n, int r) {
    chmin(r, n-r);
    if (r < 0) return M(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};