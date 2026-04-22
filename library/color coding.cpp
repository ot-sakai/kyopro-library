//Color coding
//長さkのパスやサイクルに対して有効
//各グラフに対してk色割り当て、bit dp

Random_Gen Random(0, 4);

auto f = [&]() -> bool {
    vector<int> color(n);
    for(int i = 0; i < n; i++) color[i] = Random.gen();

    vector<vector<bool>> dp((1 << 5), vector<bool>(n));
    dp[(1 << color[0])][0] = true;

    for(int i = 0; i < (1 << 5); i++) {
        for(int j = 0; j < n; j++) {
            if(!dp[i][j]) continue;

            for(auto next_v : graph[j]) {
                int c = color[next_v];
                if(!(i & (1 << c))) {
                    dp[i | (1 << c)][next_v] = true;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dp[(1 << 5) - 1][i]) {
            for(auto next_v : graph[i]) {
                if(next_v == 0) return true;
            }
        }
    }

    return false;
};

for(int iter = 0; iter < 200; iter++) {
    if(f()) {
        cout << "YES" << endl;
        return 0;
    }
}

cout << "NO" << endl;