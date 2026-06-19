//エラトステネスの篩 計算量(O(n)より少し大きい)
const int N = 2e5;
vector<bool> isp(N + 1, true);
void sieve() {
    isp[0] = true;
    isp[1] = true;
    for(int i = 2; i <= N; i++) {
        if(isp[i]) {
            for(int j = 2; i * j <= N; j++) {
                isp[i * j] = false;
            }
        }
    }
    return;
}



//Nの約数を列挙する 計算量(O(√N))
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for(ll i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            res.push_back(i);
            if(N / i != i) res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}



//高速素因数分解 計算量(前処理O(nlog n) クエリごとO(log n))
struct Eratosthenes {
    vector<bool> isprime; //テーブル
    vector<int> minfactor; //整数iを割り切る最小の素数

    //前処理
    Eratosthenes(int N) : isprime(N + 1, true), minfactor(N + 1, -1) {
        isprime[1] = false;
        minfactor[1] = 1;
        for(int p = 2; p <= N; p++) {
            if(!isprime[p]) continue;

            minfactor[p] = p;
            for(int q = p * 2; q <= N; q += p) {
                isprime[q] = false;

                if(minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    //クエリごと pair(素因数, 指数)のvectorを返す
    vector<pair<int, int>> factorize(int n) {
        vector<pair<int, int>> res;
        while(n > 1) {
            int p = minfactor[n];
            int exp = 0;

            //nで割り切れるだけ割る
            while(minfactor[n] == p) {
                n /= p;
                exp++;
            }
            res.push_back({p, exp});
        }
        return res;
    }
};
int main() { //使い方
    Eratosthenes er(N);
    for(int i = 2; i <= N; i++) {
        auto pf = er.factorize(i);
        for(int j = 0; j < pf.size(); j++) {
            pf[j].first << " " << pf[j].second;
        }
    }
}



//高速約数列挙
//1以上M以下の約数の個数が分かる 計算量(調和級数の和O(Mlog M))
vector<ll> num(M + 1);
for(int x = 1; x <= M; x++) {
    for(int y = 1; x * y <= M; y++) {
        num[x * y]++;
    }
}
//配列aの最大公約数を求めたい場合 num[x] >= nとなる最大のxが最大公約数となる
for(int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
}
vector<int> num(M + 1);
for(int x = 1; x <= M; x++) {
    for(int y = 1; x * y <= M; y++) {
        num[x] += b[x * y];
    }
}



//素因数分解 計算量O(√N)
vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for(ll a = 2; a * a <= N; a++) {
        if(N % a != 0) continue;
        ll ex = 0; //指数
        //割れるだけ割る
        while(N % a == 0) {
            N /= a;
            ex++;
        }
        res.push_back({a, ex});
    }
    //最後に残った数について
    if(N != 1) res.push_back({N, 1});
    return res;
}



//素数判定 計算量(O(√n))
bool is_prime(ll n) {
    if(n == 1) return false;
    for(ll i = 2; i * i <= N; i++) {
        if(n % i == 0) return false;
    }
    return true;
}



