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


# :warning: union_find.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

class union_find {
 private:
  int n, cnt;
  vector<int> par, rank, sz;

 public:
  union_find(int _n) : n(_n), cnt(n), par(_n), rank(_n), sz(_n) {
    iota(all(par), 0);
    fill(all(sz), 1);
  }
  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    sz[x] += sz[y];
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
#line 1 "union_find.cpp"

class union_find {
 private:
  int n, cnt;
  vector<int> par, rank, sz;

 public:
  union_find(int _n) : n(_n), cnt(n), par(_n), rank(_n), sz(_n) {
    iota(all(par), 0);
    fill(all(sz), 1);
  }
  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    sz[x] += sz[y];
    cnt--;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return sz[root(x)]; }
  int count() { return cnt; }
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

