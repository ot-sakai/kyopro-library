//座標圧縮 計算量 O(n log n)
vector<int> compress(vector<int> a) {
    vector<int> b = a; //コピー
    sort(b.begin(), b.end());

    vec_unique(b);

    int n = (int)a.size();
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    return res;
}