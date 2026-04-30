// Segment Tree Beats
// 対応クエリ:
// 1. [l, r) の値を min(A_i, x) に更新
// 2. [l, r) の値を max(A_i, x) に更新
// 3. [l, r) の A_i の最大値を求める
// 4. [l, r) の A_i の最小値を求める
// 5. [l, r) の A_i の和を求める
// 6. [l, r) の A_i に x を加える
// 7. [l, r) の A_i を x に更新

class SegmentTreeBeats {
    const ll inf = 1e18;
    int n, n0;
    vector<ll> max_v, smax_v, max_c;
    vector<ll> min_v, smin_v, min_c;
    vector<ll> sum, len, ladd, lval;

    void update_node_max(int k, ll x) {
        sum[k] += (x - max_v[k]) * max_c[k];
        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } else {
            max_v[k] = x;
        }
        if (lval[k] != inf && x < lval[k]) {
            lval[k] = x;
        }
    }

    void update_node_min(int k, ll x) {
        sum[k] += (x - min_v[k]) * min_c[k];
        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (smax_v[k] == min_v[k]) {
            min_v[k] = smax_v[k] = x;
        } else {
            min_v[k] = x;
        }
        if (lval[k] != inf && lval[k] < x) {
            lval[k] = x;
        }
    }

    void push(int k) {
        if (n0 - 1 <= k) return;

        // 区間更新 (Range Update)
        if (lval[k] != inf) {
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = inf;
            return;
        }

        // 区間加算 (Range Add)
        if (ladd[k] != 0) {
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        // Chmin 伝搬
        if (max_v[k] < max_v[2 * k + 1]) update_node_max(2 * k + 1, max_v[k]);
        if (max_v[k] < max_v[2 * k + 2]) update_node_max(2 * k + 2, max_v[k]);

        // Chmax 伝搬
        if (min_v[2 * k + 1] < min_v[k]) update_node_min(2 * k + 1, min_v[k]);
        if (min_v[2 * k + 2] < min_v[k]) update_node_min(2 * k + 2, min_v[k]);
    }

    void update(int k) {
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

        // Max 統計量の更新
        if (max_v[2 * k + 1] < max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        } else if (max_v[2 * k + 1] > max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        } else {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }

        // Min 統計量の更新
        if (min_v[2 * k + 1] < min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        } else if (min_v[2 * k + 1] > min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        } else {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void addall(int k, ll x) {
        max_v[k] += x;
        if (smax_v[k] > -0.9 * inf) smax_v[k] += x;
        min_v[k] += x;
        if (smin_v[k] < 0.9 * inf) smin_v[k] += x;

        sum[k] += len[k] * x;
        if (lval[k] != inf) {
            lval[k] += x;
        } else {
            ladd[k] += x;
        }
    }

    void updateall(int k, ll x) {
        max_v[k] = x; smax_v[k] = -inf;
        min_v[k] = x; smin_v[k] = inf;
        max_c[k] = min_c[k] = len[k];
        sum[k] = x * len[k];
        lval[k] = x; ladd[k] = 0;
    }

    // 再帰用内部関数
    void _update_min(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || max_v[k] <= x) return;
        if (a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }
        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_max(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a || x <= min_v[k]) return;
        if (a <= l && r <= b && x < smin_v[k]) {
            update_node_min(k, x);
            return;
        }
        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _add_val(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { addall(k, x); return; }
        push(k);
        _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_val(ll x, int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) { updateall(k, x); return; }
        push(k);
        _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    ll _query_max(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return -inf;
        if (a <= l && r <= b) return max_v[k];
        push(k);
        return max(_query_max(a, b, 2 * k + 1, l, (l + r) / 2),
                   _query_max(a, b, 2 * k + 2, (l + r) / 2, r));
    }

    ll _query_min(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) return min_v[k];
        push(k);
        return min(_query_min(a, b, 2 * k + 1, l, (l + r) / 2),
                   _query_min(a, b, 2 * k + 2, (l + r) / 2, r));
    }

    ll _query_sum(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return sum[k];
        push(k);
        return _query_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
               _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
    }

public:
    SegmentTreeBeats(int n) : SegmentTreeBeats(n, nullptr) {}

    SegmentTreeBeats(int _n, ll *a) : n(_n) {
        n0 = 1;
        while (n0 < n) n0 <<= 1;
        int size = 2 * n0;

        max_v.assign(size, -inf); smax_v.assign(size, -inf); max_c.assign(size, 0);
        min_v.assign(size, inf); smin_v.assign(size, inf); min_c.assign(size, 0);
        sum.assign(size, 0); len.assign(size, 0);
        ladd.assign(size, 0); lval.assign(size, inf);

        len[0] = n0;
        for (int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for (int i = 0; i < n; ++i) {
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (a != nullptr ? a[i] : 0);
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
            smax_v[n0 - 1 + i] = -inf;
            smin_v[n0 - 1 + i] = inf;
        }
        for (int i = n0 - 2; i >= 0; i--) update(i);
    }

    // A_i = min(A_i, x)
    void update_min(int l, int r, ll x) { _update_min(x, l, r, 0, 0, n0); }
    // A_i = max(A_i, x)
    void update_max(int l, int r, ll x) { _update_max(x, l, r, 0, 0, n0); }
    // A_i = A_i + x
    void add_val(int l, int r, ll x) { _add_val(x, l, r, 0, 0, n0); }
    // A_i = x
    void update_val(int l, int r, ll x) { _update_val(x, l, r, 0, 0, n0); }
    // query max
    ll query_max(int l, int r) { return _query_max(l, r, 0, 0, n0); }
    // query min
    ll query_min(int l, int r) { return _query_min(l, r, 0, 0, n0); }
    // query sum
    ll query_sum(int l, int r) { return _query_sum(l, r, 0, 0, n0); }
};