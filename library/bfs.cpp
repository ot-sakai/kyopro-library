//幅優先探索 計算量O(n + m)
vector<int> dist(n, INF2);
queue<int> que;

dist[0] = 0;
que.push(0);

//グラフ
while(!que.empty()) {
    int v = que.front();
    que.pop();

    int d = dist[v] + 1;
    for(auto next_v : graph[v]) {
        if(dist[next_v] <= d) continue;

        dist[next_v] = d;
        que.push(next_v);
    }
}


queue<pair<int, int>> que;
que.push({0, 0});
vector<vector<int>> dist(h, vector<int>(w, INF2));
dist[0][0] = 0;
//グリッド
while(!que.empty()) {
    pair<int, int> p = que.front();
    que.pop();

    int x = p.first;
    int y = p.second;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int d = dist[x][y] + 1;

        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny] == '#') continue;
        if(dist[nx][ny] <= d) continue;
        dist[nx][ny] = d;
        que.push({nx, ny});
    }
}