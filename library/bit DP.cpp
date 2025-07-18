//bit DP 計算量O(n^2 2^n)
int dp[(1 << 20)][20];

for(int i = 0; i < (1 << 20); i++) {
    for(int j = 0; j < 20; j++) {
        dp[i][j] = INF2; //初期化
    }
}
dp[0][0] = 0; //スタート地点

for(int i = 0; i < (1 << 20); i++) {
    for(int j = 0; j < 20; j++) {
        for(int k = 0; k < 20; k++) {
            if(i != 0 && !(i & (1 << k))) continue; //kを含まない場合
            if(!(i & (1 << j))) {
                if(j != k) {
                    dp[i | (1 << j)][j] = min(dp[i | (1 << j)][j], dp[i][k] + graph[k][j]);
                }
            }
        }
    }
}

if(dp[(1 << 20) - 1][0] != INF2) {
    cout << dp[(1 << 20) - 1][0] << endl;
} else {
    cout << -1 << endl;
}