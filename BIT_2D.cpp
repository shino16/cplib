struct BIT_2D {
  const int h, w;
  vector<vector<ll>> data;
  BIT_2D(int h = 0, int w = 0): h(h), w(w), data(h+1, vector<ll>(w+1)) { }
  void add(int r, int c, ll v) {
    r++; c++;
    for (; r <= h; r += r & -r)
      for (; c <= w; c += c & -c)
        data[r][c] += v;
  }
  // sum over [(0, 0), (r, c))
  ll sum(int r, int c) {
    ll res = 0;
    for (; r > 0; r -= r & -r)
      for (; c > 0; c -= c & -c)
        res += data[r][c];
  }
  // sum over [(r1, c1), (r2, c2))
  ll sum(int r1, int c1, int r2, int c2) {
    return sum(r1, c1) + sum(r2, c2) - sum(r1, c2) - sum(r2, c1);
  }
}