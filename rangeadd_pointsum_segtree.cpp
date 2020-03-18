#pragma GCC diagnostic ignored "-Wshadow"
struct segtree {
  const int n;
  vector<ll> data;
  segtree(int n = 0) : n(n) { }
  template <typename Iter>
  segtree(Iter first, Iter last, int n) : n(n), data(n<<1) {
    copy(first, last, data.begin()+n);
  }
  ll query(int l) {
    ll res = 0;
    for (l += n; l > 1; l >>= 1) res += data[l];
    return res;
  }
  void modify(int l, int r, ll v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) data[l++] += v;
      if (r&1) data[--r] += v;
    }
  }
};
#pragma GCC diagnostic warning "-Wshadow"
