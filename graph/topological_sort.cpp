
// O(V+E)
// DAG <==> res.size() == graph.size()
vector<int> topological_sort(const Graph& graph) {
  int n = graph.size();
  vector<int> in(n);
  rep(i, n) for (int to : graph[i]) in[to]++;
  stack<int> st;
  rep(i, n) if (in[i] == 0) st.push(i);
  vector<int> res;
  while (not st.empty()) {
    int i = st.top(); st.pop();
    res.push_back(i);
    for (int to : graph[i]) {
      in[to]--;
      if (in[to] == 0) st.push(to);
    }
  }
  return res;
}
