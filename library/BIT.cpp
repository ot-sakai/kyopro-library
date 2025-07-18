//BIT Binary Indexed Tree フェニック木
//最初からi番目までの区間和 計算量 O(log n)
//1-indexed
template<typename T>
struct BIT {
    int n; //配列の要素数(数列の要素数+1)
    vector<T> bit; //データの格納先．初期値は0
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}

    void add(int i, T x) { //a_i += x
        for(int idx = i; idx < n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }

    T sum(int i) { //a_1 + a_2 + ... + a_i を計算する
        T s(0);
        for(int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }

        return s;
    }
};


/* BIT: RAQ対応BIT
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template<typename T>
struct BIT {
    int n; //要素数
    vector<T> bit[2]; //データの格納先
    BIT(int n_) {init(n_);}

    void init(int n_) {
        n = n_ + 1;
        for(int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x) {
        for(int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) { //[l, r)に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i) {
        T s(0);
        for(int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { //a_1 + a_2 + ... + a_i を計算する
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }

    //任意の区間和の取得
    //[l, r)の区間和を取得
    T query(int l, int r) {
        return sum[r - l] - sum[l - 1];
    }
};

//BITで転倒数を求める 計算量O(n log n)
//BITの構造は同じ
int main() {
    for(int i = 0; i < n; i++) {
        cin >> v[i]; //配列
    }
    ll ans = 0;
    BIT<int> b(n); //これまでの数字がどんな風になっているのかをメモる為のBIT
    for(int i = 0; i < n; i++) {
        ans += i - b.sum(v[i]);
        b.add(v[i], 1);
    }

    cout << ans << endl;
}