struct SqrtCount {
    int n, B; // 配列長、ブロックサイズ
    vector<int> a; // 元の配列
    vector<vector<int>> sorted_b; // sorted_b[k] = ブロック k のソート済み要素

    SqrtCount() = default;
    explicit SqrtCount(const vector<int>& init) {build(init);}

    void build(const vector<int>& init) {
        n = (int)init.size();
        a = init;
        B = max(1, (int)sqrt((double)n));
        int num_blocks = (n + B - 1) / B;
        sorted_b.assign(num_blocks, {});
        for(int i = 0; i < n; i++) sorted_b[i / B].push_back(a[i]);
        for(auto& s : sorted_b) sort(s.begin(), s.end());
    }

    void update(int p, int v) {
        int k = p / B;
        auto& s = sorted_b[k];
        s.erase(lower_bound(s.begin(), s.end(), a[p]));
        s.insert(upper_bound(s.begin(), s.end(), v), v);
        a[p] = v;
    }

    // [l, r) のうち a[i] <= x である要素数
    int count(int l, int r, int x) {
        if(l >= r) return 0;
        int res = 0;
        int kl = l / B;
        int kr = (r - 1) / B;

        if(kl == kr) {
            // 同じブロック内は素直に線形
            for (int i = l; i < r; ++i) {
                if (a[i] <= x) ++res;
            }
            return res;
        }

        //左端 [l, (kl+1)*B)
        int l_end = (kl + 1) * B;
        for(int i = l; i < l_end; i++) {
            if(a[i] <= x) res++;
        }

        //中間の完全に含まれるブロック [kl+1, kr)
        for(int k = kl + 1; k < kr; k++) {
            const auto& s = sorted_b[k];
            res += (int)(upper_bound(s.begin(), s.end(), x) - s.begin());
        }

        //右端 [kr*B, r)
        int r_begin = kr * B;
        for(int i = r_begin; i < r; i++) {
            if(a[i] <= x) res++;
        }

        return res;
    }
};