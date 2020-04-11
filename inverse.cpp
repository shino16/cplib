
class BIT {
private:
  const int n;
  vector<ll> data;
public:
  BIT(int _n = 0): n(_n), data(_n+1) { }
  void add(int p, ll v = 1) {
    p++;
    while (p <= n) {
      data[p] += v;
      p += p & -p;
    }
  }
  // sum over [0, p)
  ll sum(int p) {
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
  BIT bit(max+1);
  ll res = 0;
  for (int i = 0; first != last; first++, i++) {
    res += i - bit.sum(*first + 1);
    bit.add(*first, 1);
  }
  return res;
}
