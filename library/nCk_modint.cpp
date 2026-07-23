//計算量 O(n + log p)
//MOD version
const int N = 2000000;

mint fac[N + 10], finv[N + 10];

void COMinit() {
    fac[0] = 1;
    for(int i = 0; i < N; i++) {
        fac[i + 1] = fac[i] * (i + 1);
    }

    const int MOD = mint::mod();
    finv[N] = inv_mod(fac[N], MOD);

    for(int i = N - 1; i >= 0; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}

mint COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;

    return fac[n] * finv[n - k] * finv[k];
}




//普通のversion
/*
    前処理: O(MAX_N*MAX_N)
    nCk(n,k): nCk の計算。O(1)
*/
const int MAX_N = 100;         // n の最大値
vector<vector<long long>> com;  // 前計算の結果を保存
// 動的計画法で前処理
void init() {
    com.assign(MAX_N, vector<long long>(MAX_N));
    com[0][0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        com[i][0] = 1;
        for (int j = 1; j < MAX_N; j++) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
        }
    }
}
// nCk を取得
long long nCk(int n, int k) {
    assert(!(n < k));
    assert(!(n < 0 || k < 0));
    return com[n][k];
}





//合成数modでの二項係数
//パスカルの三角形を使う
//計算量O(N^2)
vector<vector<int64_t>> comb(N+1, vector<int64_t>(N+1));
for(int i=0; i<=N; i++){
    comb[i][0] = comb[i][i] = 1;
    for(int j=1; j<i; j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % M;
}