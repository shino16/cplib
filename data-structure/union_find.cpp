
class union_find {
 private:
  int n, cnt;
  vector<int> par, rank, sz;

 public:
  union_find(int _n) : n(_n), cnt(_n), par(_n), rank(_n), sz(_n, 1) {
    iota(all(par), 0);
  }
  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    sz[x] += sz[y];
    cnt--;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return sz[root(x)]; }
  int count() { return cnt; }
};
