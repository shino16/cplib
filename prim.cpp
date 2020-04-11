bool operator<(const Edge &e, const Edge &f) { return e.weight > f.weight; }
pair<Weight, Edges> prim(const Graph &g, int r = 0) {
    Edges T;
    Weight total = 0;
    vector<int> vis(g.size());
    priority_queue<Edge> q;
    q.emplace(-1, r, 0);
    while (q.size()) {
        Edge e = q.top();
        q.pop();
        if (vis[e.dst]) continue;
        vis[e.dst] = true;
        total += e.weight;
        if (e.src != -1) T.emplace_back(e);
        for (auto &f : g[e.dst])
            if (!vis[f.dst]) q.emplace(f);
    }
    return make_pair(total, T);
}