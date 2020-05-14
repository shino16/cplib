#pragma once

#include "template.cpp"
#include "graph/graph.cpp"

// empty if the given graph has a negative cycle
VLL bellman_ford(const Graph& graph, int start) {
  int n = graph.size();
  VLL dist(n, INF_LL);
  dist[start] = 0;
  rep(n) {
    bool upd = false;
    rep(v, n) for (auto e : graph[v]) upd |= chmin(dist[e.to], dist[v] + e.cost);
    if (not upd) return dist;
  }
  return {};
}