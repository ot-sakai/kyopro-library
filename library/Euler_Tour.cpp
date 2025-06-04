//オイラーツアー dfs
void dfs(int current_v, int previous_v) {
    for(int next_v : graph[current_v]) {
        if(next_v == previous_v) continue; //逆流しないように

        dfs(next_v, current_v);
    }
}