/* tree_diamiter : dfs を用いて重みなし木 T の直径を求める
    計算量: O(N)
*/
pair<ll, int> dfs(const vector<vector<int>> &graph, int u, int par) {  // 最遠点間距離と最遠点を求める
    pair<ll, int> ret = make_pair((ll)0, u);
    for (auto v : graph[u]) {
        if(v == par) continue;
        auto next = dfs(graph, v, u);
        next.first += 1;
        ret = max(ret, next);
    }
    return ret;
}

ll tree_diamiter(const vector<vector<int>> &graph) {
    pair<ll, int> p = dfs(graph, 0, -1);
    pair<ll, int> q = dfs(graph, p.second, -1);
    return q.first;
}


/* tree_diamiter : dfs を用いて重み付き木 T の直径を求める
    計算量: O(N)
*/
pair<ll, int> dfs(const vector<vector<pair<int, int>>> &graph, int u, int par) {  // 最遠点間距離と最遠点を求める
    pair<ll, int> ret = make_pair((ll)0, u);
    for (auto [v, cost] : graph[u]) {
        if (v == par) continue;
        auto next = dfs(graph, v, u);
        next.first += cost;
        ret = max(ret, next);
    }
    return ret;
}

ll tree_diamiter(const vector<vector<pair<int, int>>> &graph) {
    pair<ll, int> p = dfs(graph, 0, -1);
    pair<ll, int> q = dfs(graph, p.second, -1);
    return q.first;
}