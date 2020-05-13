#pragma once

#include "template.cpp"
#include "graph/bellman-ford.cpp"
#include "graph/dijkstra.cpp"


// no negative cycle please
VVLL all_pairs_shortest_path(Graph& graph) {
  int n = graph.size();
  VLL potential = bellman_ford(graph, 0);
  rep(v, n) for (auto e : graph[v])
      e.cost += potential[v] - potential[e.to];
  VVLL res(n);
  rep(start, n) {
    res[start] = dijkstra(graph, start);
    rep(to, n)
      if (res[start][to] >= INF_LL / 8) res[start][to] = INF_LL;
      else res[start][to] += potential[to] - potential[start];
  }
  rep(v, n) for (auto e : graph[v])
      e.cost -= potential[v] - potential[e.to];
  return res;
}
