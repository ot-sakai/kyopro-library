//高速約数列挙 計算量O(δ(n)) δ(n):nの約数の個数
struct Eratosthenes {
    //テーブル
    vector<bool> isprime;

    //整数iを割り切る最小の整数
    vector<int> minfactor;

    // コンストラクタで篩を回す
    Eratosthenes(int N) : isprime(N+1, true),
                          minfactor(N+1, -1) {
        // 1 は予めふるい落としておく
        isprime[1] = false;
        minfactor[1] = 1;

        // 篩
        for (int p = 2; p <= N; ++p) {
            // すでに合成数であるものはスキップする
            if (!isprime[p]) continue;

            // p についての情報更新
            minfactor[p] = p;
            
            // p 以外の p の倍数から素数ラベルを剥奪
            for (int q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;
                
                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解
    // pair (素因子, 指数) の vector を返す
    vector<pair<int,int>> factorize(int n) {
        vector<pair<int,int>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    //高速約数列挙
    vector<int> divisors(int n) {
        vector<int> res({1});

        //nを素因数分解
        auto pf = factorize(n);

        //約数列挙
        for(auto p : pf) {
            int s = (int)res.size();
            for(int i = 0; i < s; i++) {
                int v = 1;
                for(int j = 0; j < p.second; j++) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

int main() {
    Eratosthenes er(50);

    for(int n = 2; n <= 50; n++) {
        auto dv = er.divisors(n);
    }
}


//約数の個数を調和級数で抑える O(M log M)
//1以上M以下の約数の個数が分かる
vector<ll> num(M + 1);
for(int x = 1; x <= M; x++) {
    for(int y = 1; x * y <= M; y++) {
        num[x * y]++;
    }
}