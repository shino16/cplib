#pragma once

#include "template.cpp"
#include "tree/dfs.cpp"

struct LCA {
 private:
  const int n;
  const int log2_n;

 public:
  vector<vector<int>> parent;
  vector<int> depth;
  LCA(const Graph& g, int root = 0)
      : n(g.size()),
        log2_n(32 - __builtin_clz(n) + 1),
        parent(log2_n, vector<int>(n)),
        depth(n) {
    fix([&](auto f, int v, int p, int d) -> void {
      parent[0][v] = p;
      depth[v] = d;
      for (auto& e : g[v]) {
        if (e.to != p) f(e.to, v, d + 1);
      }
    })(root, -1, 0);
    rep(k, log2_n - 1) {
      rep(v, n) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }

 public:
  int operator()(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - depth[(*this)(u, v)] * 2;
  }
};