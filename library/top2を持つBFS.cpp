//TOP2を持つBFS
//開始点を管理することでTOP2を持つようにする

//グラフ
vector<int> dist(n, INF2); //top
vector<int> dist2(n, INF2); //top2
queue<tuple<int, int, int>> que;
vector<int> from(n, -1);
for(int i = 0; i < n; i++) { //開始点
    que.push({i, 0, i});
    dist[i] = 0;
    from[i] = i;
}

while(!que.empty()) {
    auto[v, dis, f] = que.front();
    que.pop();

    int d = dis + 1;

    for(auto next_v : graph[v]) {
        if(dist2[next_v] <= d) continue;

        if(dist[next_v] > d) {
            dist[next_v] = d;
            from[next_v] = f;
            que.push({next_v, d, f});
        } else if(from[next_v] != f) {
            dist2[next_v] = d;
            que.push({next_v, d, f});
        }
    }
}