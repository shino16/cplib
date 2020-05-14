#pragma once

#include "template.cpp"
#include "graph/graph.cpp"

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
