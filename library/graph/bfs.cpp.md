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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: graph/bfs.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

struct BFS {
  VI par;
  VLL dist;
};

// unweighted graph or weighted tree
BFS bfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  BFS res;
  res.dist = VLL(n, INF_LL);
  res.par = VI(n, -1);
  res.dist[root] = 0;
  queue<int> togo;
  togo.push(root);
  while (not togo.empty()) {
    int v = togo.front(); togo.pop();
    for (auto e : graph[v])
      if (chmin(res.dist[e.to], res.dist[v]+e.cost))
        res.[e.to] = v, togo.push(e.to);
  }
  return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bfs.cpp"

struct BFS {
  VI par;
  VLL dist;
};

// unweighted graph or weighted tree
BFS bfs(const Graph& graph, int root = 0) {
  int n = graph.size();
  BFS res;
  res.dist = VLL(n, INF_LL);
  res.par = VI(n, -1);
  res.dist[root] = 0;
  queue<int> togo;
  togo.push(root);
  while (not togo.empty()) {
    int v = togo.front(); togo.pop();
    for (auto e : graph[v])
      if (chmin(res.dist[e.to], res.dist[v]+e.cost))
        res.[e.to] = v, togo.push(e.to);
  }
  return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

