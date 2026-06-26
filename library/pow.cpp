//繰り返し二乗法を用いた高速なべき乗計算(計算量O(log n))
ll mypow(ll x, ll n) {
    if(x == 0) return 0;
    ll ret = 1;
    while(n > 0) {
        if(n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

//繰り返し二乗法を用いた高速なべき乗計算(計算量O(log n))
//MOD version
ll powmod(ll x, ll n, ll MOD) {
    if(x == 0) return 0;
    ll ret = 1;
    while(n > 0) {
        if(n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret;
}

//繰り返し二乗法を用いた高速なべき乗計算(計算量O(log n))
//オーバーフロー → -1
ll mypow(lll x, ll n) {
    if(x == 0) return 0;
    lll ret = 1;
    bool flag = false;
    while(n > 0) {
        if(n & 1) {
            if(flag) return -1;
            ret *= x;
            if(ret > 1e18) return -1; 
        }
        if(!flag) x *= x;
        if(x > 1e18) flag = true;
        n >>= 1;
    }
    return ret;
}