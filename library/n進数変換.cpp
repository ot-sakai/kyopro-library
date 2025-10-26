//n進数変換
//10進数xをn進数に変換する
string f(ll x, int n) {
    string s;
    while(x != 0) {
        int r = x % n;
        x /= n;
        s = (char)(r + '0') + s;
    }
    return s;
}