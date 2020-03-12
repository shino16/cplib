struct binomial {
  vector<modint> fact, invfact;
  // O(n)
  binomial(int n): fact(n+1), invfact(n+1) {
    fact[0] = 1;
    rep(i, n) fact[i+1] = fact[i] * modint(i+1);
    invfact[n] = modint(1) / fact[n];
    repr(i, n) invfact[i] = invfact[i+1] * modint(i+1);
  }
  // O(1)
  modint operator()(int n, int r) {
    chmin(r, n-r);
    if (r < 0) return modint(0);
    return fact[n] * invfact[r] * invfact[n-r];
  }
};