void euler_tour(const VVI& graph, VI& tour, VI& left, VI& right,
                int v = 0, int par = -1) {
  left[v] = tour.size();
  tour.push_back(v);
  for (auto next : graph[v])
    if (next != par) euler_tour(graph, tour, range, next, v);
  tour.push_back(v);
  right[v] = tour.size();
}
