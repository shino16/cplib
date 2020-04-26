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


# :warning: tree_diameter.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree_diameter.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 15:35:53+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

PII dfs(const VVI& g, int idx, int par) {
  PII ret(0, idx);
  for (auto& e : g[idx]) {
    if (e == par) continue;
    chmax(ret, dfs(g, e, idx) + 1);
  }
  return ret;
}

int tree_diameter(const VVI& g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return q.first;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree_diameter.cpp"

PII dfs(const VVI& g, int idx, int par) {
  PII ret(0, idx);
  for (auto& e : g[idx]) {
    if (e == par) continue;
    chmax(ret, dfs(g, e, idx) + 1);
  }
  return ret;
}

int tree_diameter(const VVI& g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return q.first;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

