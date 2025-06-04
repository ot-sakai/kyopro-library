//01bfs 計算量O(n + m)
vector<int> dist(n, INF2);
dist[0] = 0;
deque<int> que;
que.push_back(0);

//グラフ
while(!que.empty()) {
    int v = que.front();
    que.pop_front();
    for(auto [next_v, c] : graph[v]) {
        int d = dist[v] + c;
        if(d < dist[next_v]) {
            dist[next_v] = d;
            if(c == 1) {
                que.push_back(next_v);
            } else {
                que.push_front(next_v);
            }
        }
    }
}

//グリッド
vector<vector<int>> dist(h, vector<int>(w, INF2));
deque<pair<int, int>> que;
dist[0][0] = 0;
que.push_front({0, 0});

while(!que.empty()) {
    pair<int, int> p = que.front();
    que.pop_front();

    int x = p.first;
    int y = p.second;

    //コスト0の場合
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny] == '#') continue;

        int d = dist[x][y];
        if(d < dist[nx][ny]) {
            dist[nx][ny] = d;
            que.push_front({nx, ny});
        }
    }

    //コスト1の場合
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny] == '#') continue;

        int d = dist[x][y] + 1;
        if(d < dist[nx][ny]) {
            dist[nx][ny] = d;
            que.push_back({nx, ny});
        }
    }
}