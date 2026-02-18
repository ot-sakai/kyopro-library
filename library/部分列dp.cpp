//next[i][c] := i文字目以降で最初に文字cが登場するindex(存在しない場合はn)
vector<vector<int>> next(n + 1, vector<int>(26, n));
for(int i = n - 1; i >= 0; i--) {
    for(int j = 0; j < 26; j++) {
        next[i][j] = next[i + 1][j];
    }
    next[i][s[i] - 'a'] = i;
}

vector<mint> dp(n + 1);
dp[0] = 1; //空文字列
for(int i = 0; i < n; i++) {
    for(int j = 0; j < 26; j++) {
        if(next[i][j] == n) continue;
        dp[next[i][j] + 1] += dp[i];
    }
}

//集計
mint ans = 0;
for(int i = 0; i <= n; i++) {
    ans += dp[i];
}

cout << ans.val() << endl;