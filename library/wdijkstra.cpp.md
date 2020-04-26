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


# :warning: wdijkstra.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/wdijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

template <typename Weight>
using Graph = vector<vector<pair<int, Weight>>>;

template <typename Weight>
using P = pair<Weight, int>;

template <typename Weight>
vector<Weight> dijkstra(const Graph<Weight>& graph, int start) {
  priority_queue<P, vector<P>, greater<P>> q;
  vector<Weight> dist(graph.size(), numeric_limits<Weight>::max());
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    Weight d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    rep(i, graph[v].size()) {
      int to; Weight w;
      tie(to, w) = graph[v][i];
      if (chmin(dist[to], dist[v] + w)) q.emplace(dist[to], to);
    }
  }
  return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "wdijkstra.cpp"

template <typename Weight>
using Graph = vector<vector<pair<int, Weight>>>;

template <typename Weight>
using P = pair<Weight, int>;

template <typename Weight>
vector<Weight> dijkstra(const Graph<Weight>& graph, int start) {
  priority_queue<P, vector<P>, greater<P>> q;
  vector<Weight> dist(graph.size(), numeric_limits<Weight>::max());
  dist[start] = 0;
  q.emplace(0, start);

  while (not q.empty()) {
    Weight d; int v;
    tie(d, v) = q.top(); q.pop();
    if (dist[v] < d) continue;
    rep(i, graph[v].size()) {
      int to; Weight w;
      tie(to, w) = graph[v][i];
      if (chmin(dist[to], dist[v] + w)) q.emplace(dist[to], to);
    }
  }
  return dist;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

