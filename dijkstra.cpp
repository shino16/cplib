using Graph = vector<vector<int>>;

vector<int> dijkstra(const Graph& graph, int start) {
  using P = pair<int, int>;
  priority_queue<P, vector<P>, greater<P>> q;
  vector<int> dist(graph.size(), numeric_limits<int>::max());
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