#pragma once

#include "template.cpp"

vector<ll> dijkstra(const Graph& graph, int start) {
  minheap<pair<ll, int>> q;
  vector<ll> dist(graph.size(), INF_LL);
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], dist[v] + e.cost)) q.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}
