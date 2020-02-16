struct BIT {
  const int n;
  vector<ll> data;
  BIT(int n): n(n), data(n+1) { }
  void add(int p, ll v) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
    p++;
    ll res = 0;
    while (p) {
      res += data[p];
      p -= p & -p;
    }
    return res;
  }
  // sum over [l, r)
  ll sum(int l, int r) {
    return sum(r) - sum(l);
  }
};
