struct union_find {
  int n;
  vector<int> par, rank;
  union_find(int n): n(n), par(n), rank(n) {
    iota(all(par), 0);
    fill(all(rank), 0);
  }
  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  void merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) par[x] = y;
    else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};