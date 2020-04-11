vector<int> dijkstra(const VVI& graph, int start) {
  minheap<pair<int, int>> q;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    if (dist[v] < d) continue;
    rep(i, graph[v].size()) {
      int to = graph[v][i];
      if (chmin(dist[to], dist[v] + 1)) q.emplace(dist[to], to);
    }
  }
  return dist;
}