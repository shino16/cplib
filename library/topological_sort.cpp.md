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


# :warning: topological_sort.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:09:17+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp

typedef vector<vector<int>> Graph;

// O(V+E)
// DAG <==> res.size() == graph.size()
vector<int> topological_sort(const Graph& graph) {
  int n = graph.size();
  vector<int> in(n);
  rep(i, n) for (int to : graph[i]) in[to]++;
  stack<int> st;
  rep(i, n) if (in[i] == 0) st.push(i);
  vector<int> res;
  while (not st.empty()) {
    int i = st.top(); st.pop();
    res.push_back(i);
    for (int to : graph[i]) {
      in[to]--;
      if (in[to] == 0) st.push(to);
    }
  }
  return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "topological_sort.cpp"

typedef vector<vector<int>> Graph;

// O(V+E)
// DAG <==> res.size() == graph.size()
vector<int> topological_sort(const Graph& graph) {
  int n = graph.size();
  vector<int> in(n);
  rep(i, n) for (int to : graph[i]) in[to]++;
  stack<int> st;
  rep(i, n) if (in[i] == 0) st.push(i);
  vector<int> res;
  while (not st.empty()) {
    int i = st.top(); st.pop();
    res.push_back(i);
    for (int to : graph[i]) {
      in[to]--;
      if (in[to] == 0) st.push(to);
    }
  }
  return res;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

