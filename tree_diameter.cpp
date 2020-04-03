PII dfs(const VVI& g, int idx, int par) {
  PII ret(0, idx);
  for(auto &e : g[idx]) {
    if(e == par) continue;
    chmax(ret, dfs(g, e, idx)+1);
  }
  return ret;
}

int tree_diameter(const VVI& g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}
