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


# :warning: tree/rerooting.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 23:43:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Edge, typename Apply, typename Merge>
class ReRooting {
public:
  struct Node {
    int to, rev;
    Edge data;
    Node(int to, Edge data) : to(to), data(data) {}
    bool operator<(const Node &v) const { return to < v.to; };
  };

private:
  vector<vector<Node>> G;
  vector<vector<T>> ld, rd;
  vector<int> lp, rp;

  const T id;
  const Apply apply;
  const Merge merge;

public:
  ReRooting(int n, T id, const Apply &apply = Apply(),
            const Merge &merge = Merge())
      : G(n), ld(n), rd(n), lp(n), rp(n), id(id), apply(apply), merge(merge) {}

  // d: propagate v to u
  void add_edge(int u, int v, Edge d, Edge e) {
    G[u].emplace_back(v, d);
    G[v].emplace_back(u, e);
  }

  void add_edge(int u, int v, Edge d) { add_edge(u, v, d, d); }

private:
  // k: idx for edge (not vertex)
  T dfs(int v, int k) {
    while (lp[v] != k and lp[v] < (int)G[v].size()) {
      const auto &e = G[v][lp[v]];
      ld[v][lp[v] + 1] = merge(ld[v][lp[v]], apply(dfs(e.to, e.rev), e.data));
      lp[v]++;
    }
    if (k < 0) return ld[v].back();
    while (rp[v] != k and rp[v] >= 0) {
      const auto &e = G[v][rp[v]];
      rd[v][rp[v]] = merge(rd[v][rp[v] + 1], apply(dfs(e.to, e.rev), e.data));
      rp[v]--;
    }
    return merge(ld[v][k], rd[v][k + 1]);
  }

  int search(vector<Node> &vs, int idx) {
    return lower_bound(all(vs), Node(idx, vs[0].data)) - vs.begin();
  }

public:
  vector<T> build() {
    int n = G.size();
    for (int i = 0; i < n; i++) {
      sort(all(G[i]));
      ld[i].assign((int)G[i].size() + 1, id);
      rd[i].assign((int)G[i].size() + 1, id);
      lp[i] = 0;
      rp[i] = (int)G[i].size() - 1;
    }

    for (int i = 0; i < n; i++)
      for (Node &t : G[i]) t.rev = search(G[t.to], i);

    vector<T> res;
    for (int i = 0; i < n; i++) res.emplace_back(dfs(i, -1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v, int p) {
    int k = search(G[p], v);
    assert(k < (int)G[p].size() and G[p][k].to == v);
    return apply(dfs(v, G[p][k].rev), G[p][k].data);
  }
};
#pragma GCC diagnostic pop

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/rerooting.cpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
template <typename T, typename Edge, typename Apply, typename Merge>
class ReRooting {
public:
  struct Node {
    int to, rev;
    Edge data;
    Node(int to, Edge data) : to(to), data(data) {}
    bool operator<(const Node &v) const { return to < v.to; };
  };

private:
  vector<vector<Node>> G;
  vector<vector<T>> ld, rd;
  vector<int> lp, rp;

  const T id;
  const Apply apply;
  const Merge merge;

public:
  ReRooting(int n, T id, const Apply &apply = Apply(),
            const Merge &merge = Merge())
      : G(n), ld(n), rd(n), lp(n), rp(n), id(id), apply(apply), merge(merge) {}

  // d: propagate v to u
  void add_edge(int u, int v, Edge d, Edge e) {
    G[u].emplace_back(v, d);
    G[v].emplace_back(u, e);
  }

  void add_edge(int u, int v, Edge d) { add_edge(u, v, d, d); }

private:
  // k: idx for edge (not vertex)
  T dfs(int v, int k) {
    while (lp[v] != k and lp[v] < (int)G[v].size()) {
      const auto &e = G[v][lp[v]];
      ld[v][lp[v] + 1] = merge(ld[v][lp[v]], apply(dfs(e.to, e.rev), e.data));
      lp[v]++;
    }
    if (k < 0) return ld[v].back();
    while (rp[v] != k and rp[v] >= 0) {
      const auto &e = G[v][rp[v]];
      rd[v][rp[v]] = merge(rd[v][rp[v] + 1], apply(dfs(e.to, e.rev), e.data));
      rp[v]--;
    }
    return merge(ld[v][k], rd[v][k + 1]);
  }

  int search(vector<Node> &vs, int idx) {
    return lower_bound(all(vs), Node(idx, vs[0].data)) - vs.begin();
  }

public:
  vector<T> build() {
    int n = G.size();
    for (int i = 0; i < n; i++) {
      sort(all(G[i]));
      ld[i].assign((int)G[i].size() + 1, id);
      rd[i].assign((int)G[i].size() + 1, id);
      lp[i] = 0;
      rp[i] = (int)G[i].size() - 1;
    }

    for (int i = 0; i < n; i++)
      for (Node &t : G[i]) t.rev = search(G[t.to], i);

    vector<T> res;
    for (int i = 0; i < n; i++) res.emplace_back(dfs(i, -1));

    return res;
  }

  // p: idx for vertex
  T subtree(int v, int p) {
    int k = search(G[p], v);
    assert(k < (int)G[p].size() and G[p][k].to == v);
    return apply(dfs(v, G[p][k].rev), G[p][k].data);
  }
};
#pragma GCC diagnostic pop

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

