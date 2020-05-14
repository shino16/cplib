#pragma once

#include "template.cpp"
#include "graph/graph.cpp"

struct BFS {
  VI par;
  VLL dist;
};

// unweighted graph or weighted tree
BFS bfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  BFS res;
  res.dist = VLL(n, INF_LL);
  res.par = VI(n, -1);
  res.dist[root] = 0;
  queue<int> togo;
  togo.push(root);
  while (not togo.empty()) {
    int v = togo.front(); togo.pop();
    for (auto e : graph[v])
      if (chmin(res.dist[e.to], res.dist[v]+e.cost))
        res.[e.to] = v, togo.push(e.to);
  }
  return res;
}
