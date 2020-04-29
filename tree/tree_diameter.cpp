#pragma once

ll tree_diameter(const Graph& g) {
  auto dfs = fix([&](auto f, int idx, int par)->PLL{
    PLL ret(0, idx);
    for (auto& e : g[idx]) {
      if (e == par) continue;
      chmax(ret, dfs(g, e, idx) + e.cost);
    }
    return ret;
  };
  auto p = dfs(0, -1);
  auto q = dfs(p.second, -1);
  return q.first;
}
