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


# :warning: dijkstra.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<int> dijkstra(const VVI& graph, int start) {
  minheap<pair<int, int>> q;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    if (dist[v] < d) continue;
    rep(i, graph[v].size()) {
      int to = graph[v][i];
      if (chmin(dist[to], dist[v] + 1)) q.emplace(dist[to], to);
    }
  }
  return dist;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "dijkstra.cpp"
vector<int> dijkstra(const VVI& graph, int start) {
  minheap<pair<int, int>> q;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    if (dist[v] < d) continue;
    rep(i, graph[v].size()) {
      int to = graph[v][i];
      if (chmin(dist[to], dist[v] + 1)) q.emplace(dist[to], to);
    }
  }
  return dist;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

