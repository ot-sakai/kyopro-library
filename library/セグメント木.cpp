//1点更新・区間MAX取得
//モノイド
int op(int a, int b) {
    return max(a, b);
}

//単位元
int e() {
    return -1;
}

int main() {
    segtree<int, op, e> seg(n); //宣言
}

//1点更新・区間GCD取得
int op(int a, int b) {
    return gcd(a, b);
}
int e() {
    return 0;
}

//1点更新・区間XOR取得
int op(int a, int b) {
    return a^b;
}
int e() {
    return 0;
}