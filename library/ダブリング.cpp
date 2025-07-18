//ダブリング 計算量O(n log k)
//要素数n個，遷移数k回
//dp[i][j] : 地点jから2^i回移動した地点
//0 <= i <= log k, 1 <= j <= n

vector<vector<int>> dp(61, vector<int>(n));
//初期条件(1回移動した地点)
for(int j = 0; j < n; j++) {
    dp[0][j] = a[j];
}

//遷移
for(int i = 1; i < 61; i++) {
    for(int j = 0; j < n; j++) {
        dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
}

//解を求める
int ans = 0;
int i = 0;

while(k) {
    if(k & 1) {
        ans = dp[i][ans];
    }
    k >>= 1;
    i++;
}

cout << ans << endl;