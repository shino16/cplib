#pragma once

#include "template.cpp"

class TwoEdgeConnectedComponents {
private:
  VI ord, low, par, index, sz;
public:
  VVI components; Graph c_graph;

public:
  TwoEdgeConnectedComponents() {}
  TwoEdgeConnectedComponents(const Graph& graph)
      : ord(graph.size(), -1), low(graph.size()), par(graph.size(), -1), index(graph.size(), -1), sz(graph.size(), 1) {
    int n = graph.size();
    rep(i, n) if (ord[i] == -1) dfs(i, graph);
    rep(i, n) if (index[i] == -1) add_component(i, graph);
    c_graph = Graph(components.size());
    rep(v, n) for (int u : graph[v])
        if (index[v] != index[u]) c_graph[index[v]].emplace_back(index[u]);
  }

private:
  int t = 0;
  void dfs(int v, const Graph& graph) {
    ord[v] = low[v] = t++;
    int dup = 0;
    for (int u : graph[v]) {
      if (u == par[v] and !dup) dup = 1;
      else if (ord[u] != -1) chmin(low[v], ord[u]);
      else {
        par[u] = v;
        dfs(u, graph);
        sz[v] += sz[u];
        chmin(low[v], low[u]);
      }
    }
  }

  void fill_component(int v, const Graph& graph) {
    components[index[v]].emplace_back(v);
    for (int u : graph[v]) if (index[u] == -1 and not is_bridge(u, v)) {
      index[u] = index[v];
      fill_component(u, graph);
    }
  }

  void add_component(int v, const Graph& graph) {
    index[v] = components.size();
    components.emplace_back();
    fill_component(v, graph);
  }

public:
  bool is_bridge(int u, int v) const {
    if (ord[u] > ord[v]) swap(u, v);
    return ord[u] < low[v];
  }

  int operator[](int v) const { return index[v]; }
};
