//エラトステネスの区間篩
//vが合成数ならば、ある√v以下の素数pが存在して、vはpで割り切れる
//√B以下の各素数p=2,3,5,7...に対して、A以上B以下のpの倍数をふるい落とす

// √B 以下の素数を炙り出すための篩
// ここでは大きめにサイズ 1100000 まで確保しておく
vector<bool> isprime(1100000, true);

ll A, B;

// A 以上 B 以下の整数 v が素数かどうか
// その答えは isprime2[v-A] に格納される
vector<bool> isprime2(B - A + 1, true);

// ふるい
for (long long p = 2; p * p <= B; ++p) {
    // すでに合成数であるものはスキップする
    if (!isprime[p]) continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (long long q = p * 2; q * q <= B; q += p) {
        isprime[q] = false;
    }

    // start: A 以上の最小の p の倍数
    long long start = (A + p - 1) / p * p;
    if (start == p) start = p * 2;

    // A 以上 B 以下の整数のうち、p の倍数をふるう
    for (long long q = start; q <= B; q += p) {
        isprime2[q - A] = false;
    }
}

// 答え
long long res = 0;
for (long long q = A; q <= B; ++q) {
    if (isprime2[q - A]) ++res;
}

cout << res << endl;