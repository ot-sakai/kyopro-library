//繰り返し二乗法を用いた高速なべき乗計算(計算量O(log n))
ll pow(ll x, ll n) {
    ll ret = 1;
    while(n > 0) {
        if(n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

const int MOD = 998244353;
//繰り返し二乗法を用いた高速なべき乗計算(計算量O(log n))
//MOD version
ll pow(ll x, ll n) {
    ll ret = 1;
    while(n > 0) {
        if(n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret;
}