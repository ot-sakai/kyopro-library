vector<vector<pair<int, int>>> graph(2 * n + 1); //頂点数を2倍
for(int i = 0; i < m; i++) { //入力
    graph[u].push_back({v, a});
    graph[v].push_back({u, a});
    graph[u + n].push_back({v + n, a});
    graph[v + n].push_back({u + n, a});
}

