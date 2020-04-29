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


# :warning: tree/euler_tour.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/euler_tour.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:28:13+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

void euler_tour(const VVI& graph, VI& tour, VI& left, VI& right,
                int v = 0, int par = -1) {
  left[v] = tour.size();
  tour.push_back(v);
  for (auto next : graph[v])
    if (next != par) euler_tour(graph, tour, left, right, next, v);
  tour.push_back(v);
  right[v] = tour.size();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/euler_tour.cpp"

void euler_tour(const VVI& graph, VI& tour, VI& left, VI& right,
                int v = 0, int par = -1) {
  left[v] = tour.size();
  tour.push_back(v);
  for (auto next : graph[v])
    if (next != par) euler_tour(graph, tour, left, right, next, v);
  tour.push_back(v);
  right[v] = tour.size();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

