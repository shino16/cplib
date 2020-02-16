struct weighted_union_find {
  int n;
  vector<int> par, rank;
  weighted_union_find(int n): n(n), par(n), rank(n), diff_weight(n) {
    iota(all(par), 0);
    fill(all(rank), 0);
    fill(all(diff_weight), 0);
  }
  int root(int x) {
    if (par[x] == x) {
      return x;
    }
    int r = root(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }
  int weight(int x) {
    root(x);
    return diff_weight[x];
  }
  // x to y
  int diff(int x, int y) {
    return weight(y) - weight(x);
  }
  // weight[y] - weight[x] = w
  void merge(int x, int y, int w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    diff_weight[y] = w;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
private:
  vector<int> diff_weight;
};