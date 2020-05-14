#pragma once

#include "template.cpp"
#include "graph/graph.cpp"
#include "util/fix.cpp"

ll tree_diameter(const Graph& g) {
  auto dfs = fix([&](auto f, int v, int par)->PLL{
    PLL ret(0, v);
    for (auto& e : g[v]) {
      if (e.to == par) continue;
      auto ch = f(e.to, v);
      ch.first += e.cost;
      chmax(ret, ch);
    }
    return ret;
  });
  auto p = dfs(0, -1);
  auto q = dfs(p.second, -1);
  return q.first;
}
