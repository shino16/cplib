#pragma once

#include "data-structure/fibonacci_heap.cpp"

vector<ll> dijkstra(const Graph& graph, int start) {
  fibonacci_heap<ll, int, greater<>> q;
  vector<ll> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      ll d2 = d + e.cost;
      if (chmin(dist[e.to], d2)) {
        if (handles[e.to].expired()) handles[e.to] = q.push(d2, e.to);
        else q.prioritize(handles[e.to], d2);
      }
    }
  }
  return dist;
}