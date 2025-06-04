//木の直径を求める 計算量O(n + m)
queue<int> que;
que.push(0);
vector<int> dist(n, -1);
dist[0] = 0;

while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(auto next_v : graph[v]) {
        if(dist[next_v] == -1) {
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}

int u = 0;
int d = -1;
for(int i = 0; i < n; i++) {
    if(dist[i] > d) {
        d = dist[i];
        u = i;
    }
}

que.push(u);
dist.assign(n, -1);
dist[u] = 0;

while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(auto next_v : graph[v]) {
        if(dist[next_v] == -1) {
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}

d = -1;
int v = 0;
for(int i = 0; i < n; i++) {
    if(dist[i] > d) {
        d = dist[i];
        v = i;
    }
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