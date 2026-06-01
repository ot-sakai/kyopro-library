//部分集合dp
//メモ化再帰
//O(N 3^N)
vector<vector<ll>> dp(k + 1, vector<ll>((1 << n), INF));
auto dfs = [&](auto dfs, int k, int s) -> ll {
    if(k == 1) return dp[k][s] = dist[s];
    if(dp[k][s] != INF) return dp[k][s];

    ll res = INF;
    auto a = s;
    while(a > 0) {
        ll tmp = max(dist[s ^ a], dfs(dfs, k - 1, a));
        res = min(res, tmp);
        a = (a - 1) & s;
    }
    
    return dp[k][s] = res;
};

ll ans = dfs(dfs, k, (1 << n) - 1);