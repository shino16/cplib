class BIT {
public:
  const int n;
private:
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
  void assign(int p, ll v) {
    add(p, v - sum(p, p+1));
  }
  bool chmax(int p, ll v) {
    if (sum(p, p+1) < v) {
      assign(p, v);
      return true;
    } else return false;
  }
};
