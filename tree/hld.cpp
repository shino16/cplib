
// originally written by @beet-aizu
class HLD {
 private:
  VI index, sz, par, rev;
  // last vertex in ascending heavy path
  VI nxt;

 public:
  HLD(Graph& graph)
      : index(graph.size()), sz(graph.size(), 1),
        par(graph.size(), -1), rev(graph.size()), nxt(graph.size()) {
    dfs_sz(graph, 0);
    dfs_hld(graph, 0);
  }

 private:
  void dfs_sz(Graph& graph, int v) {
    if (graph[v].size() >= 2 and graph[v][0] == par[v])
      swap(graph[v][0], graph[v][1]);
    for (auto& c : graph[v])
      if (c != par[v]) {
        par[c] = v;
        dfs_sz(graph, c);
        sz[v] += sz[c];
        if (sz[c] > sz[graph[v][0]]) swap(c, graph[v][0]);
      }
  }

  void dfs_hld(const Graph& graph, int v) {
    static int t = 0;
    index[v] = t++;
    rev[index[v]] = v;
    for (auto c : graph[v])
      if (c != par[v]) {
        nxt[c] = (c.to == graph[v][0].to ? nxt[v] : c.to);
        dfs_hld(graph, c);
      }
    assert(sz[v] == t - index[v]);
  }

 public:
  template <typename F>
  void path_vertex(int u, int v, F f) {
    while (true) {
      if (index[u] > index[v]) swap(u, v);
      // debug(u); debug(v);
      // debug(nxt[u]); debug(index[u]);
      f(max(index[nxt[v]], index[u]), index[v] + 1);
      if (nxt[u] != nxt[v])
        v = par[nxt[v]];
      else
        break;
    }
  }

  template <typename F>
  void path_edge(int u, int v, F f) {
    while (true) {
      if (index[u] > index[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(index[nxt[v]], index[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v) f(index[u] + 1, index[v] + 1);
        break;
      }
    }
  }

  template <typename F>
  void subtree_vertex(int v, F f) {
    f(index[v], index[v] + sz[v]);
  }

  template <typename F>
  void subtree_edge(int v, F f) {
    f(index[v] + 1, index[v] + sz[v]);
  }

  int lca(int u, int v) {
    while (1) {
      if (index[u] > index[v]) swap(u, v);
      if (nxt[u] == nxt[v]) return u;
      v = par[nxt[v]];
    }
  }

  int subtree_size(int v) { return sz[v]; }

  int vertex(int v) { return index[v]; }

  int parent(int v) { return par[v]; }

  int restore(int ix) { return rev[ix]; }
};
