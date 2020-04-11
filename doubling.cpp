typedef vector<vector<int>> graph;

class doubling {
private:
  const int n = 0;
  const int log2_n = 0;

public:
  // parent[k][v]: parent of v distant by 2^k
  vector<vector<int>> parent;
  vector<int> depth;

  doubling(const graph& g, int root = 0)
      : n(g.size()), log2_n(32 - __builtin_clz(n) + 1),
        parent(log2_n, vector<int>(n)), depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < (int)g.size(); v++) {
        if (parent[k][v] < 0)
          parent[k+1][v] = -1;
        else
          parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

private:
  void dfs(const graph& g, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (auto &e : g[v]) {
      if (e != p) dfs(g, e, v, d + 1);
    }
  }
};