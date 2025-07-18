//LIS(最長増加部分列)
//dp[i][h]:=最初のi項のみを考えた場合の単調増加な部分列であって、
//最後の要素がhであるような場合についての、最長の長さ

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return 0;
}

int LIS(const vector<ll> &a) {
    int n = (int)a.size();

    //座標圧縮
    vector<ll> aval;
    for(int i = 0; i < n; i++) aval.push_back(a[i]);
    sort(aval.begin(), aval.end());
    vec_unique(aval);

    //セグ木(区間max)
    segtree<int, op, e> dp(n + 1);

    int res = 0;
    for(int i = 0; i < n; i++) {
        int h = lower_bound(aval.begin(), aval.end(), a[i]) - aval.begin();
        h++; //1-indexedにする

        //値取得
        int b = dp.prod(0, h);
        //同じ値が連続することを許す場合
        //int b = dp.prod(0, h + 1);

        //更新
        if(dp.get(h) < b + 1) {
            dp.set(h, b + 1);
            res = max(res, b + 1);
        } 
    }
    return res;
}