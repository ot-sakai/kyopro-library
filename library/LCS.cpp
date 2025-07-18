//LCS 最長共通部分列 O(|s||t|)
string s, t;
cin >> s >> t;
int n = s.size();
int m = t.size();
vector<vector<int>> dp(n + 1, vector<int>(m + 1));
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        if(s[i - 1] == t[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

cout << dp[n][m] << endl;

//LCSを復元
int i = n;
int j = m;
string ans = "";
while(i > 0 && j > 0) {
    if(s[i - 1] == t[j - 1]) {
        ans = s[i - 1] + ans;
        i--;
        j--;
    } else {
        if(dp[i][j] == dp[i][j - 1]) j--;
        else i--;
    }
}
cout << ans << endl;