#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include "template.cpp"
#include "data-structure/fibonacci_heap.cpp"
#include "graph/dijkstra_fib_heap.cpp"


int main() {
  int n = IN, m = IN, r = IN;
  Graph graph(n);
  rep(m) {
    int u = IN, v = IN, d = IN;
    graph[u].emplace_back(v, d);
  }
  auto d = dijkstra(graph, r);
  rep(i, n) OUT(d[i] >= INF ? "INF" : to_string(d[i]));
}