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


# :warning: data-structure/weighted_union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/weighted_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

class weighted_union_find {
  int n, cnt;
  vector<int> par, rank, sz, diff_weight;
  weighted_union_find(int n)
      : n(n), cnt(n), par(n), rank(n), sz(n), diff_weight(n) {
    iota(all(par), 0);
  }
  int root(int x) {
    if (par[x] == x) return x;
    int r = root(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }
  int weight(int x) {
    root(x);
    return diff_weight[x];
  }
  // y - x
  int diff(int x, int y) { return weight(y) - weight(x); }
  // y - x = w
  void merge(int x, int y, int w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    sz[x] += sz[y];
    diff_weight[y] = w;
    cnt--;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return sz[root(x)]; }
  int count() { return cnt; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/weighted_union_find.cpp"

class weighted_union_find {
  int n, cnt;
  vector<int> par, rank, sz, diff_weight;
  weighted_union_find(int n)
      : n(n), cnt(n), par(n), rank(n), sz(n), diff_weight(n) {
    iota(all(par), 0);
  }
  int root(int x) {
    if (par[x] == x) return x;
    int r = root(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }
  int weight(int x) {
    root(x);
    return diff_weight[x];
  }
  // y - x
  int diff(int x, int y) { return weight(y) - weight(x); }
  // y - x = w
  void merge(int x, int y, int w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    sz[x] += sz[y];
    diff_weight[y] = w;
    cnt--;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return sz[root(x)]; }
  int count() { return cnt; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

