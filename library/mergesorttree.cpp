//merge sort tree
//区間[l, r)内でx未満の値の個数
//前処理O(nlogn) クエリごとO(log^2 n)

template<typename T>
struct mergesorttree {
    int n;
    vector<vector<T>> tree;

    mergesorttree(const vector<T> &a) {
        n = 1;
        while(n < a.size()) n *= 2;
        tree.resize(2 * n - 1);

        //葉ノードの構築
        for(int i = 0; i < a.size(); i++) {
            tree[i + n - 1].push_back(a[i]);
        }

        //下から順にマージ
        for(int i = n - 2; i >= 0; i--) {
            merge(tree[2 * i + 1].begin(), tree[2 * i + 1].end(), tree[2 * i + 2].begin(), tree[2 * i + 2].end(), back_inserter(tree[i]));
        }
    }

    //区間[l, r)において値がval未満である要素数を返す
    int query(int l, int r, T val) {
        return query(l, r, val, 0, 0, n);
    }

private:
    int query(int l, int r, T val, int k, int cl, int cr) {
        if(r <= cl || cr <= l) return 0; //完全に範囲外
        if(l <= cl && cr <= r) {
            // 区間が完全に含まれる場合、そのノード内で二分探索
            return lower_bound(tree[k].begin(), tree[k].end(), val) - tree[k].begin();
        }
        //子ノードへ
        int mid = (cl + cr) / 2;
        return query(l, r, val, 2 * k + 1, cl, mid) + query(l, r, val, 2 * k + 2, mid, cr);
    }
};