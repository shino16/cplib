struct FEdge {
    int from, to;
    ll cost;
};

bool operator<(const Edge &e, const Edge &f) { return e.cost < f.cost; }
pair<ll, vector<FEdge>> prim(const Graph &g, int r = 0) {
    vector<FEdge> T;
    ll total = 0;
    VB visited(g.size());
    priority_queue<Edge> q;
    q.emplace({-1, r, 0});
    while (q.size()) {
        FEdge e = q.top();
        q.pop();
        if (visited[e.to]) continue;
        visited[e.to] = true;
        total += e.cost;
        if (e.from != -1) T.push_back(e);
        for (auto &f : g[e.to])
            if (!visited[f.to]) q.push(f);
    }
    return make_pair(total, T);
}