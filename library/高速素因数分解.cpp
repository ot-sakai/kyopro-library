//高速素因数分解 計算量O(log n)

//エラトステネスの篩 計算量O(nlog n)
struct Eratosthenes {
    //テーブル
    vector<bool> isprime;
    //整数iを割り切る最小の素数
    vector<int> minfactor;

    //コンストラクタで篩を回す
    Eratosthenes(int N) : isprime(N+1, true), minfactor(N+1, -1) {
        isprime[1] = false;
        minfactor[1] = 1;

        for(int p = 2; p <= N; p++) {
            //すでに合成数であるものはスキップ
            if(!isprime[p]) continue;
            
            //pについての情報更新
            minfactor[p] = p;

            //p以外のpの倍数から素数ラベルを剥奪
            for(int q = p * 2; q <= N; q += p) {
                isprime[q] = false;

                //qはpで割り切れる旨を更新
                if(minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    //高速素因数分解 計算量O(log n)
    //pair(素因数, 指数)のvectorを返す
    vector<pair<int, int>> factorize(int n) {
        vector<pair<int, int>> res;
        while(n > 1) {
            int p = minfactor[n];
            int exp = 0;

            //nで割り切れる限り割る
            while(minfactor[n] == p) {
                n /= p;
                exp++;
            }
            res.push_back({p, exp});
        }
        return res;
    }
};


int main() {
    Eratosthenes er(50);

    // 結果表示
    for (int n = 2; n <= 50; ++n) {
        auto pf = er.factorize(n);
        cout << n << ": ";
        for (int i = 0; i < pf.size(); ++i) {
            if (i > 0) cout << " * ";
            cout << pf[i].first << "^" << pf[i].second;
        }
        cout << endl;
    }
}