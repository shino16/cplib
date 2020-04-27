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


# :warning: util/random_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/random_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 18:46:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

// C++ Implementation for random
// tree generator using Prufer Sequence

// Prints edges of tree
// represented by give Prufer code
VVI makeGraph(int prufer[], int m) {
  int n = m + 2;
  VI vertex_set(n);
  vector<PII> edges;

  rep(i, m) vertex_set[prufer[i]-1]++;

  // Find the smallest label not present in
  // prufer[].
  rep(i, m) {
    rep(j, n) if (vertex_set[j] == 0) {
      vertex_set[j] = -1;
      edges.emplace_back(j, prufer[i]-1);
      vertex_set[prufer[i]-1]--;
      break;
    }
  }

  VI rest;
  rep(i, n) if (vertex_set[i] == 0) rest.push_back(i);
  edges.emplace_back(rest[0], rest[1]);

  VVI graph(n);
  for (auto p : edges)
    graph[p._1].push_back(p._2),
    graph[p._2].push_back(p._1);

  return graph;
}

// generate random numbers in between l an r
int ran(int l, int r)
{
  debug(l);
  debug(r);
  int res = l + (rand() % (r - l + 1));
  debug(res);
  return res;
}

// Function to Generate Random Tree
VVI generateRandomTree(int n)
{

  int length = n - 2;
  int arr[length];

  // Loop to Generate Random Array
  for (int i = 0; i < length; i++)
  {
    arr[i] = ran(0, pow(2, i)) + 1;
  }
  return makeGraph(arr, length);
}

// This code is contributed by Arnab Kundu
// and me

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/random_tree.cpp"

// C++ Implementation for random
// tree generator using Prufer Sequence

// Prints edges of tree
// represented by give Prufer code
VVI makeGraph(int prufer[], int m) {
  int n = m + 2;
  VI vertex_set(n);
  vector<PII> edges;

  rep(i, m) vertex_set[prufer[i]-1]++;

  // Find the smallest label not present in
  // prufer[].
  rep(i, m) {
    rep(j, n) if (vertex_set[j] == 0) {
      vertex_set[j] = -1;
      edges.emplace_back(j, prufer[i]-1);
      vertex_set[prufer[i]-1]--;
      break;
    }
  }

  VI rest;
  rep(i, n) if (vertex_set[i] == 0) rest.push_back(i);
  edges.emplace_back(rest[0], rest[1]);

  VVI graph(n);
  for (auto p : edges)
    graph[p._1].push_back(p._2),
    graph[p._2].push_back(p._1);

  return graph;
}

// generate random numbers in between l an r
int ran(int l, int r)
{
  debug(l);
  debug(r);
  int res = l + (rand() % (r - l + 1));
  debug(res);
  return res;
}

// Function to Generate Random Tree
VVI generateRandomTree(int n)
{

  int length = n - 2;
  int arr[length];

  // Loop to Generate Random Array
  for (int i = 0; i < length; i++)
  {
    arr[i] = ran(0, pow(2, i)) + 1;
  }
  return makeGraph(arr, length);
}

// This code is contributed by Arnab Kundu
// and me

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

