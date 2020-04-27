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


# :warning: graph/dijkstra_fib_heap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra_fib_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

vector<int> dijkstra(const VVI& graph, int start) {
  fibonacci_heap<int, int, greater<>> q;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto to : graph[v]) {
      int d2 = d + 1;
      if (chmin(dist[v], d2)) {
        if (handles[to].expired()) handles[to] = q.push(d2, to);
        else q.prioritize(handles[to], d2);
      }
    }
  }
  return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra_fib_heap.cpp"

vector<int> dijkstra(const VVI& graph, int start) {
  fibonacci_heap<int, int, greater<>> q;
  vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    auto [d, v] = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto to : graph[v]) {
      int d2 = d + 1;
      if (chmin(dist[v], d2)) {
        if (handles[to].expired()) handles[to] = q.push(d2, to);
        else q.prioritize(handles[to], d2);
      }
    }
  }
  return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

