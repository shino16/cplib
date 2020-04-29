#pragma once

template <size_t N>
class binomial {
public:
  array<modint, N+1> fact, invfact;
  constexpr binomial() {
    fact[0] = 1;
    rep(i, N) fact[i+1] = fact[i] * modint(i+1);
    invfact[N] = modint(1) / fact[N];
    repr(i, N) invfact[i] = invfact[i+1] * modint(i+1);
  }
  modint operator()(int n, int r) const {
    chmin(r, n-r);
    if (r < 0) return modint(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};
