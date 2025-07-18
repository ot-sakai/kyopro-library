//ゲームDP 逆算！！
//石取りゲーム
bool dp[100010];
int k; //石の個数 初期状態
vector<int> a(n); //山から a0,,,an のいずれかの個数の石をとる
for(int i = 0; i < n; i++) cin >>a[i];

dp[0] = false;
for(int i = 1; i <= k; i++) {
    for(int j = 0; j < n; j++) {
        if(i - a[j] >= 0) dp[i] |= !dp[i - a[j]];
    }
}

if(dp[k]) cout << "First" << endl; //先手勝利
else cout << "Second" << endl; //後手勝利


//得点差最大化ゲーム
//終局状態
dp[h - 1][w - 1] = 0;

//終局から逆算していく
for(int i = h - 1; i >= 0; i--) {
    for(int j = w - 1; j >= 0; j--) {
        if(i + 1 < h) { //駒を下に動かす場合
            if(a[i + 1][j] == '+') dp[i][j] = max(dp[i][j], -dp[i + 1][j] + 1);
            else dp[i][j] = max(dp[i][j], -dp[i + 1][j] - 1);
        }

        if(j + 1 < w) { //駒を右に動かす場合
            if(a[i][j + 1] == '+') dp[i][j] = max(dp[i][j], -dp[i][j + 1] + 1);
            else dp[i][j] = max(dp[i][j], -dp[i][j + 1] - 1);
        }
    }
}

if(dp[0][0] > 0) cout << "Takahashi" << endl;
else if(dp[0][0] < 0) cout << "Aoki" << endl;
else cout << "Draw" << endl;