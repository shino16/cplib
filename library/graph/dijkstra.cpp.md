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


# :heavy_check_mark: graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/GRL_1_A.test.cpp.html">verify/aoj/GRL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

vector<ll> dijkstra(const Graph& graph, int start) {
  minheap<pair<ll, int>> q;
  vector<ll> dist(graph.size(), INF_LL);
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], dist[v] + e.cost)) q.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/dijkstra.cpp"

vector<ll> dijkstra(const Graph& graph, int start) {
  minheap<pair<ll, int>> q;
  vector<ll> dist(graph.size(), INF_LL);
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    ll d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], dist[v] + e.cost)) q.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
