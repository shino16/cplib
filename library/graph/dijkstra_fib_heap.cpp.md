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


# :heavy_check_mark: graph/dijkstra_fib_heap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra_fib_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 00:04:22+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/GRL_1_A_fh.test.cpp.html">verify/aoj/GRL_1_A_fh.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

vector<ll> dijkstra(const Graph& graph, int start) {
  fibonacci_heap<ll, int, greater<>> q;
  vector<ll> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      ll d2 = d + e.cost;
      if (chmin(dist[e.to], d2)) {
        if (handles[e.to].expired()) handles[e.to] = q.push(d2, e.to);
        else q.prioritize(handles[e.to], d2);
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

vector<ll> dijkstra(const Graph& graph, int start) {
  fibonacci_heap<ll, int, greater<>> q;
  vector<ll> dist(graph.size(), INF);
  dist[start] = 0;
  q.push(0, start);
  vector<decltype(q)::node_handle> handles(graph.size());
  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      ll d2 = d + e.cost;
      if (chmin(dist[e.to], d2)) {
        if (handles[e.to].expired()) handles[e.to] = q.push(d2, e.to);
        else q.prioritize(handles[e.to], d2);
      }
    }
  }
  return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

