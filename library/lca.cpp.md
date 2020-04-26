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


# :warning: lca.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/lca.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
typedef vector<vector<int>> graph;

struct lca {
private:
  const int n = 0;
  const int log2_n = 0;
public:
  vector<vector<int>> parent;
  vector<int> depth;
  lca(const graph &g, int root)
      : n(g.size()), log2_n(32 - __builtin_clz(n) + 1),
        parent(log2_n, vector<int>(n)), depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < (int)g.size(); v++) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
private:
  void dfs(const graph &g, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (auto &e : g[v]) {
      if (e != p) dfs(g, e, v, d + 1);
    }
  }
public:
  int operator()(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lca.cpp"
typedef vector<vector<int>> graph;

struct lca {
private:
  const int n = 0;
  const int log2_n = 0;
public:
  vector<vector<int>> parent;
  vector<int> depth;
  lca(const graph &g, int root)
      : n(g.size()), log2_n(32 - __builtin_clz(n) + 1),
        parent(log2_n, vector<int>(n)), depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < (int)g.size(); v++) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
private:
  void dfs(const graph &g, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (auto &e : g[v]) {
      if (e != p) dfs(g, e, v, d + 1);
    }
  }
public:
  int operator()(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

