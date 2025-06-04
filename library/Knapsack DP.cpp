//ナップサックdp 計算量O(nw)
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= w; j++) {
        dp[i + 1][j] = dp[i][j];
    }

    for(int j = 0; j <= w; j++) {
        if(dp[i][j - weight[i]] == -1) continue;
        if(j >= weight[i]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);
    }
}