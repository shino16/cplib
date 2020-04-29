#include "util/fix.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};
