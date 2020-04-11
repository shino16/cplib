
class BIT_2D {
private:
  const int h, w;
  vector<vector<ll>> data;
public:
  BIT_2D(int h, int w): h(h), w(w), data(h+1, vector<ll>(w+1)) { }
  void add(int r, int c, ll v) {
    r++; c++;
    int c0 = c;
    for (; r <= h; r += r & -r)
      for (c = c0; c <= w; c += c & -c)
        data[r][c] += v;
  }
  // sum over [(0, 0), (r, c))
  ll sum(int r, int c) {
    ll res = 0;
    int c0 = c;
    for (; r > 0; r -= r & -r)
      for (c = c0; c > 0; c -= c & -c)
        res += data[r][c];
    return res;
  }
  // sum over [(r1, c1), (r2, c2))
  ll sum(int r1, int c1, int r2, int c2) {
    return sum(r1, c1) + sum(r2, c2) - sum(r1, c2) - sum(r2, c1);
  }
};
