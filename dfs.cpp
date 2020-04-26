
struct DFS {
  VI subtree_sz, par;
  VLL dist;
};

// tree
DFS dfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  DFS res;
  res.subtree_sz = VI(n, 1);
  res.par = VI(n, -1);
  res.dist = VLL(n, INF_LL);
  res.dist[root] = 0;
  _dfs_impl(graph, root, res);
  return res;
}

void _dfs_impl(const Graph& graph, int v, DFS& res) {
  for (auto e : graph[v])
    if (e.to != res.par[v])
      res.dist[e.to] = res.dist[v] + e.cost,
      res.par[e.to] = v,
      _dfs_impl(graph, e.to, res),
      res.subtree_sz[v] += res.subtree_sz[e.to];
}
