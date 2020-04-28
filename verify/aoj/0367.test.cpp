#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367"
// "https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Prelim/0367?year=2017"

#include "template.cpp"
#include "data-structure/segtree.cpp"
#include "tree/hld.cpp"
#include "util/compress.cpp"

struct Path {
  array<int, 2> to;
  ll cost;
  Path(int u = -1, int v = -1, ll _cost = -1) : to({min(u, v), max(u, v)}), cost(_cost) {}
  bool operator==(const Path& rhs) const { return to == rhs.to; }
  bool operator<(const Path& rhs) const { return to < rhs.to; }
};

int main() {
  int n = IN, k = IN;

  Graph graph(n);
  VLL weight(n);
  Compress<Path> edges;

  rep(n - 1) {
    int a = IN, b = IN, c = IN;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    edges.emplace(a, b, c);
  }

  HLD hld(graph);

  auto merge_path = [&](const Path& a, const Path& b) {
    if (a.cost == -1) return b; else if (b.cost == -1) return a;
    auto edge_cost = [&](int u, int v) {
      ll res = weight[u] + weight[v]
               + edges.restore(edges[Path(u, v)]).cost;
      return res % k ? res : 0;
    };
    rep(i, 2) rep(j, 2)
      if (edges.count(Path(a.to[i], b.to[j])))
        return Path(a.to[i ^ 1], b.to[j ^ 1],
                    a.cost + b.cost + edge_cost(a.to[i], b.to[j]));
    return Path();
  };

  auto do_nothing = [](auto x, auto y) { return x; };

  vector<Path> paths(n);
  rep(i, n) paths[i] = Path(hld.restore(i), hld.restore(i), 0);

  SegmentTree<Path, decltype(merge_path), decltype(do_nothing)>
    segtree(paths.begin(), paths.end(), n, Path(), merge_path, do_nothing);

  rep(IN) {
    string cmd = IN; int x = IN, y = IN;
    if (cmd[0] == 'a') weight[x] += y, segtree.modify(hld.vertex(x), Path());
    else {
      Path r1, r2;
      int z = hld.lca(x, y);
      hld.path_vertex(x, z, [&](auto l, auto r){ r1 = merge_path(r1, segtree.fold(l, r)); });
      hld.path_edge(y, z, [&](auto l, auto r){ r2 = merge_path(r2, segtree.fold(l, r)); });
      OUT(merge_path(r1, r2).cost);
    }
  }
}
