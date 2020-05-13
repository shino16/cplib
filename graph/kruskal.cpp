#pragma once

#include "data-structure/union-find.cpp"
#include "template.cpp"

struct FEdge {
  int from, to;
  ll cost;
};

bool operator<(const Edge& e, const Edge& f) { return e.cost < f.cost; }
bool operator>(const Edge& e, const Edge& f) { return e.cost > f.cost; }

pair<ll, vector<FEdge>> kruskal(const Graph& graph) {
  int n = graph.size();
  vector<FEdge> edges;
  rep(v, n) for (auto e : graph[v])
    if (v < e.to) edges.emplace_back(FEdge{v, e.to, e.cost});
  sort(all(edges));

  ll total = 0;
  vector<FEdge> res;
  UnionFind uf(n);
  for (auto e : edges) if (not uf.same(e.from, e.to))
    total += e.cost, uf.merge(e.from, e.to);
  return make_pair(total, move(res));
}