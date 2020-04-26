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


# :warning: prim.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
bool operator<(const Edge &e, const Edge &f) { return e.weight > f.weight; }
pair<Weight, Edges> prim(const Graph &g, int r = 0) {
    Edges T;
    Weight total = 0;
    vector<int> vis(g.size());
    priority_queue<Edge> q;
    q.emplace(-1, r, 0);
    while (q.size()) {
        Edge e = q.top();
        q.pop();
        if (vis[e.dst]) continue;
        vis[e.dst] = true;
        total += e.weight;
        if (e.src != -1) T.emplace_back(e);
        for (auto &f : g[e.dst])
            if (!vis[f.dst]) q.emplace(f);
    }
    return make_pair(total, T);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "prim.cpp"
bool operator<(const Edge &e, const Edge &f) { return e.weight > f.weight; }
pair<Weight, Edges> prim(const Graph &g, int r = 0) {
    Edges T;
    Weight total = 0;
    vector<int> vis(g.size());
    priority_queue<Edge> q;
    q.emplace(-1, r, 0);
    while (q.size()) {
        Edge e = q.top();
        q.pop();
        if (vis[e.dst]) continue;
        vis[e.dst] = true;
        total += e.weight;
        if (e.src != -1) T.emplace_back(e);
        for (auto &f : g[e.dst])
            if (!vis[f.dst]) q.emplace(f);
    }
    return make_pair(total, T);
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

