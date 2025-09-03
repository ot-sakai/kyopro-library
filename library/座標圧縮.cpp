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

// 座標圧縮（順位付け）- タイを潰さないバージョン
vector<int> compress_ranked(const vector<int>& a) {
    int n = a.size();

    // 値と元のインデックスをセットで持つ
    vector<pair<int, int>> val_index(n);
    for (int i = 0; i < n; ++i) {
        val_index[i] = {a[i], i};
    }

    // 値を基準に安定ソート（同じ値なら元の順を維持）
    stable_sort(val_index.begin(), val_index.end());

    // ランクをつける（0始まり）
    vector<int> res(n);
    for (int rank = 0; rank < n; ++rank) {
        res[val_index[rank].second] = rank;
    }

    return res;
}