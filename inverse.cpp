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

template <typename Iter>
ll inverse(Iter first, Iter last) {
  int n = distance(first, last);
  int max = *max_element(first, last);
  BIT bit(max);
  ll res = 0;
  for (int i = 0; first != last; first++, i++) {
    res += i - bit.sum(*first + 1);
    bit.add(*first, 1);
  }
  return res;
}