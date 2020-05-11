#pragma once

#include "template.cpp"
#include "data-structure/binary-heap.cpp"

vector<ll> dijkstra(const Graph& graph, int start) {
  BinaryHeap<ll, greater<>> hp;
  vector<ll> dist(graph.size(), INF_LL);
  dist[start] = 0;
  hp.emplace(start, 0);

  while (not hp.empty()) {
    ll d = hp.top();
    int v = hp.top_index();
    hp.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], dist[v] + e.cost)) hp.prioritize(e.to, dist[e.to]);
    }
  }
  return dist;
}