#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0366"

#include "template.cpp"
#include "graph/strongly-connected-components.cpp"
#include "util/fast-io.cpp"

int main() {
  int n = IN, m = IN;
  Graph graph(n);
  rep(m) {
    int u = IN, v = IN;
    graph[u].emplace_back(v);
  }
  Graph c_graph = StronglyConnectedComponents(graph).c_graph;
  if (c_graph.size() == 1) ({ OUT(0); exit(0); });
  VI source, dest;
  VI in(c_graph.size()), out(c_graph.size());
  rep(v, c_graph.size()) for (auto e : c_graph[v]) out[v]++, in[e.to]++;
  rep(v, c_graph.size()) if (in[v] == 0) source.push_back(v);
  rep(v, c_graph.size()) if (out[v] == 0) dest.push_back(v);
  OUT(max(source.size(), dest.size()));
}
