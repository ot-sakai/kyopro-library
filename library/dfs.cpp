//深さ優先探索 計算量O(n + m)
//グラフ
void dfs(int v) {
    seen[v] = true;

    for(auto next_v : graph[v]) {
        if(!seen[next_v]) {
            dfs(next_v);
        }
    }
}

//グリッド
void dfs(int x, int y) {
    seen[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny] == '#') continue;
        if(!seen[nx][ny]) {
            dfs(nx, ny);
        }
    }
}