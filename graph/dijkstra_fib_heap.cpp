
vector<int> dijkstra(const VVI& graph, int start) {
  fibonacci_heap<int, int, greater<>> q;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto to : graph[v]) {
      int d2 = d + 1;
      if (chmin(dist[v], d2)) {
        if (handles[to].expired()) handles[to] = q.push(d2, to);
        else q.prioritize(handles[to], d2);
      }
    }
  }
  return dist;
}
