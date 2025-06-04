//単純パスの数え上げ dfs 計算量(完全グラフで頂点1から頂点Nへの単純パス数θ((n - 1)!))
void dfs(int v) {
    seen[v] = true;
    result++;
    for(auto next_v : graph[v]) {
        if(!seen[next_v]) {
            dfs(next_v);
        }
    }
    seen[v] = false;
    return;
}

//グリッド
void dfs(int x, int y) {
    seen[x][y] = true;
    result++;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(!seen[nx][ny] && c[nx][ny] == '.') {
            dfs(nx, ny, v);
        }
    }
    seen[x][y] = false;
    return;
}