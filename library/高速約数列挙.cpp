//約数の個数を調和級数で抑える O(M log M)
//1以上M以下の約数の個数が分かる
vector<ll> num(M + 1);
for(int x = 1; x <= M; x++) {
    for(int y = 1; x * y <= M; y++) {
        num[x * y]++;
    }
}




//配列aの最大公約数を求めたい場合
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

//num[x] >= nとなる最大のxが最大公約数となる