//桁DP
//基本形 dp[i][smaller(bool)][j:制約]

mint dp[10010][2][110];
dp[0][0][0] = 1;
string s;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < d; j++) {
        // i桁目まででNより小さいならi+1桁目は何でも良い
        for(int k = 0; k < 10; k++) {
            dp[i + 1][1][(j + k) % d] += dp[i][1][j];
        }

        int ni = (s[i] - '0');

        // i桁目までNと同じで、i+1桁目はNより小さい数の時
        for(int k = 0; k < ni; k++) {
            dp[i + 1][1][(j + k) % d] += dp[i][0][j];
        }

        //  i桁目までNと同じで、i+1桁目もNと同じ数の時
        dp[i + 1][0][(ni + j) % d] += dp[i][0][j];
    }
}

//0のときを引くため、-1
cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;