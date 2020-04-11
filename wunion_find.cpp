class weighted_union_find {
  int n, cnt;
  vector<int> par, rank, sz, diff_weight;
  weighted_union_find(int n)
      : n(n), cnt(n), par(n), rank(n), sz(n), diff_weight(n) {
    iota(all(par), 0);
  }
  int root(int x) {
    if (par[x] == x) return x;
    int r = root(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }
  int weight(int x) {
    root(x);
    return diff_weight[x];
  }
  // y - x
  int diff(int x, int y) { return weight(y) - weight(x); }
  // y - x = w
  void merge(int x, int y, int w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    sz[x] += sz[y];
    diff_weight[y] = w;
    cnt--;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return sz[root(x)]; }
  int count() { return cnt; }
};