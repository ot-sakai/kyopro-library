//木DP 計算量O(n)
void dfs(int current_v, int previous_v) {
    int dp_cum = 0; //計算用変数
    for(int next_v : graph[current_v]) {
        if(next_v == previous_v) continue; //逆流しないように

        dfs(next_v, current_v);
        dp_cum = ; //計算
    }
    dp[current_v] = dp_cum; //計算結果を代入
}