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


# :heavy_check_mark: graph/strongly-connected-components.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly-connected-components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 10:43:15+09:00




## Depends on

* :heavy_check_mark: <a href="../util/fix.cpp.html">util/fix.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/aoj/0366.test.cpp.html">verify/aoj/0366.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "util/fix.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "util/fix.cpp"

template <typename F>
class FixPoint : private F {
 public:
  explicit constexpr FixPoint(F&& f) : F(forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template <typename F> decltype(auto) fix(F&& f) noexcept {
  return FixPoint<F>{forward<F>(f)};
}
#line 2 "graph/strongly-connected-components.cpp"

class StronglyConnectedComponents {
 private:
  VI index;
 public:
  VVI components; Graph c_graph;

  StronglyConnectedComponents() {}
  StronglyConnectedComponents(const Graph& graph) : index(graph.size(), -1) {
    int n = graph.size();
    Graph rev_graph(n);
    rep(v, n) for (auto e : graph[v]) rev_graph[e.to].emplace_back(v, e.cost);

    VI ord;
    VB done(n);
    auto dfs = fix([&](auto f, int v)->void{
      done[v] = true;
      for (auto e : graph[v]) if (not done[e.to]) f(e.to);
      ord.push_back(v);
    });
    rep(v, n) if (not done[v]) dfs(v);

    auto rev_dfs = fix([&](auto f, int v)->void{
      components.back().push_back(v);
      index[v] = components.size() - 1;
      for (auto e : rev_graph[v]) if (index[e] == -1) f(e.to);
    });

    repr(i, n) if (index[ord[i]] == -1) components.emplace_back(), rev_dfs(ord[i]);

    fill(done.begin(), done.begin()+components.size(), false);
    c_graph = Graph(components.size());
    rep(i, components.size()) {
      done[i] = true;
      for (auto v : components[i])
        for (auto e : graph[v])
          if (not done[index[e.to]])
            done[index[e.to]] = true, c_graph[i].emplace_back(index[e.to]);
      done[i] = false;
      for (auto j : c_graph[i]) done[j] = false;
    }
  }

  int operator[](int v) { return index[v]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

