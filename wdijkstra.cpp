
template <typename Weight>
using Graph = vector<vector<pair<int, Weight>>>;

template <typename Weight>
using P = pair<Weight, int>;

template <typename Weight>
vector<Weight> dijkstra(const Graph<Weight>& graph, int start) {
  priority_queue<P, vector<P>, greater<P>> q;
  vector<Weight> dist(graph.size(), numeric_limits<Weight>::max());
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    Weight d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    rep(i, graph[v].size()) {
      int to; Weight w;
      tie(to, w) = graph[v][i];
      if (chmin(dist[to], dist[v] + w)) q.emplace(dist[to], to);
    }
  }
  return dist;
}
