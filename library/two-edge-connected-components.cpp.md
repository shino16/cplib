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


# :warning: two-edge-connected-components.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/two-edge-connected-components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

// originally written by @beet-aizu
class TwoEdgeConnectedComponents {
private:
  VI ord, low, par, index, sz;
public:
  VVI components, c_graph;

public:
  TwoEdgeConnectedComponents(const Graph& graph)
      : ord(graph.size(), -1), low(graph.size()), par(graph.size(), -1), index(graph.size(), -1), sz(graph.size(), 1) {
    int n = graph.size();
    rep(i, n) if (ord[i] == -1) dfs(i, graph);
    rep(i, n) if (index[i] == -1) add_component(i, graph);
    c_graph = VVI(components.size());
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
  bool is_bridge(int u, int v) {
    if (ord[u] > ord[v]) swap(u, v);
    return ord[u] < low[v];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "two-edge-connected-components.cpp"

// originally written by @beet-aizu
class TwoEdgeConnectedComponents {
private:
  VI ord, low, par, index, sz;
public:
  VVI components, c_graph;

public:
  TwoEdgeConnectedComponents(const Graph& graph)
      : ord(graph.size(), -1), low(graph.size()), par(graph.size(), -1), index(graph.size(), -1), sz(graph.size(), 1) {
    int n = graph.size();
    rep(i, n) if (ord[i] == -1) dfs(i, graph);
    rep(i, n) if (index[i] == -1) add_component(i, graph);
    c_graph = VVI(components.size());
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
  bool is_bridge(int u, int v) {
    if (ord[u] > ord[v]) swap(u, v);
    return ord[u] < low[v];
  }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

