#pragma once

#include "template.cpp"

struct FEdge {
  int from, to;
  ll cost;
};

bool operator<(const Edge& e, const Edge& f) { return e.cost < f.cost; }
bool operator>(const Edge& e, const Edge& f) { return e.cost > f.cost; }

pair<ll, vector<FEdge>> prim(const Graph& graph) {
  ll total = 0;
  vector<FEdge> res;
  int n = graph.size();
  VB done(n, false);
  minheap<FEdge> hp;
  done[0] = true;
  for (auto e : graph[0]) hp.emplace(FEdge{0, e.to, e.cost});
  while (not hp.empty()) {
    FEdge e = hp.top(); hp.pop();
    if (done[e.to]) continue;
    total += e.cost;
    res.push_back(e);
    done[e.to] = true;
    for (auto f : graph[e.to])
      if (not done[f.to]) hp.emplace(FEdge{e.to, f.to, f.cost});
  }
  return make_pair(total, move(res));
}