---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: hld.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/hld.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class HLD {
 private:
  VI index, sz, par;
  // last vertex in ascending heavy path
  VI nxt;

 public:
  HLD(Graph& graph)
      : index(graph.size()),
        sz(graph.size(), 1),
        par(graph.size(), -1),
        nxt(graph.size()) {
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
    for (auto c : graph[v])
      if (c != par[v]) {
        nxt[c] = (c == graph[v][0] ? nxt[v] : c);
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
  void subtree_vertex(int u, F f) {
    f(index[u], index[u] + sz[u]);
  }

  template <typename F>
  void subtree_edge(int u, F f) {
    f(index[u] + 1, index[u] + sz[u]);
  }

  int lca(int u, int v) {
    while (1) {
      if (index[u] > index[v]) swap(u, v);
      if (nxt[u] == nxt[v]) return u;
      v = par[nxt[v]];
    }
  }

  int subtree_size(int v) { return sz[v]; }

  int vertex(int u) { return index[u]; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "hld.cpp"

class HLD {
 private:
  VI index, sz, par;
  // last vertex in ascending heavy path
  VI nxt;

 public:
  HLD(Graph& graph)
      : index(graph.size()),
        sz(graph.size(), 1),
        par(graph.size(), -1),
        nxt(graph.size()) {
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
    for (auto c : graph[v])
      if (c != par[v]) {
        nxt[c] = (c == graph[v][0] ? nxt[v] : c);
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
  void subtree_vertex(int u, F f) {
    f(index[u], index[u] + sz[u]);
  }

  template <typename F>
  void subtree_edge(int u, F f) {
    f(index[u] + 1, index[u] + sz[u]);
  }

  int lca(int u, int v) {
    while (1) {
      if (index[u] > index[v]) swap(u, v);
      if (nxt[u] == nxt[v]) return u;
      v = par[nxt[v]];
    }
  }

  int subtree_size(int v) { return sz[v]; }

  int vertex(int u) { return index[u]; }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

