//サイクル検出(有向グラフ)
vector<bool> visied;
vector<bool> finished;
bool cycle = false;
void dfs(int v) {
    visited[v] = true;
    for(auto next_v : graph[v]) {
        if(!visited[next_v]) {
            dfs(next_v);
        } else if(!finished[next_v]) {
            cycle = true;
        }
    }
    finished[v] = true;
}