//半分全列挙 計算量 O(2^(n / 2)n)
// グループ１をビット全探索で全列挙 (前半の半分)
vector<ll> A;
for(int bit = 0; bit < (1 << n / 2); bit++) {
    ll sum = 0;
    for(int i = 0; i < n / 2; i++) {
        if(bit & (1 << i)) {

        }
    }
    A.push_back(sum);
}

// グループ2をビット全探索で全列挙 (後半の半分)
vector<ll> B;
for(int bit = 0; bit < (1 << (n - n / 2)); bit++) {
    ll sum = 0;
    for(int i = 0; i < (n - n / 2); i++) {
        if(bit & (1 << i)) {
            
        }
    }
    B.push_back(sum);
}

sort(B.begin(), B.end()); //Bをソート

// A の要素を固定して二分探索
ll ans = 0;
for(auto a : A) {
    if() {
        upper_bound(B.begin(), B.end(), );
    }
}