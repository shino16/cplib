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


# :warning: graph/prim.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct FEdge {
    int from, to;
    ll cost;
};

bool operator<(const Edge &e, const Edge &f) { return e.cost < f.cost; }
pair<ll, vector<FEdge>> prim(const Graph &g, int r = 0) {
    vector<FEdge> T;
    ll total = 0;
    VB visited(g.size());
    priority_queue<Edge> q;
    q.emplace({-1, r, 0});
    while (q.size()) {
        FEdge e = q.top();
        q.pop();
        if (visited[e.to]) continue;
        visited[e.to] = true;
        total += e.cost;
        if (e.from != -1) T.push_back(e);
        for (auto &f : g[e.to])
            if (!visited[f.to]) q.push(f);
    }
    return make_pair(total, T);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/prim.cpp"
struct FEdge {
    int from, to;
    ll cost;
};

bool operator<(const Edge &e, const Edge &f) { return e.cost < f.cost; }
pair<ll, vector<FEdge>> prim(const Graph &g, int r = 0) {
    vector<FEdge> T;
    ll total = 0;
    VB visited(g.size());
    priority_queue<Edge> q;
    q.emplace({-1, r, 0});
    while (q.size()) {
        FEdge e = q.top();
        q.pop();
        if (visited[e.to]) continue;
        visited[e.to] = true;
        total += e.cost;
        if (e.from != -1) T.push_back(e);
        for (auto &f : g[e.to])
            if (!visited[f.to]) q.push(f);
    }
    return make_pair(total, T);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

