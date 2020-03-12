struct union_find {
  int n;
  vector<int> par, rank, sz;
  union_find(int n): n(n), par(n), rank(n), sz(n) {
    iota(all(par), 0);
    fill(all(sz), 1);
  }
  int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  void merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    sz[x] += sz[y];
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return sz[root(x)];
  }
};