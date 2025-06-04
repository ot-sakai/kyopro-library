ll Kruskal(vector<tuple<ll, int, int>> &edges, int n) {
    sort(edges.begin(), edges.end()); //辺の重みの昇順
    dsu d(n);
    ll res = 0;
    for(auto[w, u, v] : edges) {
        if(!d.same(u, v)) {
            d.merge(u, v);
            res += w;
        }
    }
    return res;
}