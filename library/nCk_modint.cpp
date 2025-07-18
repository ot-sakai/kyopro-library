//計算量 O(n + log p)
//MOD version
const int MAX = 2000000;
mint fac[MAX], finv[MAX], inv[MAX];

//前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

//二項係数計算
mint COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
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