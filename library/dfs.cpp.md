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


# :warning: dfs.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/dfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

struct DFS {
  VI subtree_sz, par;
  VLL dist;
};

// tree
DFS dfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  DFS res;
  res.subtree_sz = VI(n, 1);
  res.par = VI(n, -1);
  res.dist = VLL(n, INF_LL);
  res.dist[root] = 0;
  _dfs_impl(graph, root, res);
  return res;
}

void _dfs_impl(const Graph& graph, int v, DFS& res) {
  for (auto e : graph[v])
    if (e.to != res.par[v])
      res.dist[e.to] = res.dist[v] + e.cost,
      res.par[e.to] = v,
      _dfs_impl(graph, e.to, res),
      res.subtree_sz[v] += res.subtree_sz[e.to];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "dfs.cpp"

struct DFS {
  VI subtree_sz, par;
  VLL dist;
};

// tree
DFS dfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  DFS res;
  res.subtree_sz = VI(n, 1);
  res.par = VI(n, -1);
  res.dist = VLL(n, INF_LL);
  res.dist[root] = 0;
  _dfs_impl(graph, root, res);
  return res;
}

void _dfs_impl(const Graph& graph, int v, DFS& res) {
  for (auto e : graph[v])
    if (e.to != res.par[v])
      res.dist[e.to] = res.dist[v] + e.cost,
      res.par[e.to] = v,
      _dfs_impl(graph, e.to, res),
      res.subtree_sz[v] += res.subtree_sz[e.to];
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

