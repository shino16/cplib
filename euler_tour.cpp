void euler_tour(const VVI& graph, VI& tour, VVI& range, int v = 0, int par = -1) {
  range[v].push_back(tour.size());
  tour.push_back(v);
  for (auto next : graph[v])
    if (next != par) euler_tour(graph, tour, range, next, v);
  tour.push_back(v);
  range[v].push_back(tour.size());
}