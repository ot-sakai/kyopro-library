//fenwick tree上の二分探索
//「挿入」，「削除」，「K番目を取得」のときに有効

fenwick_tree<int> fw(n); //indexを管理するBIT
fenwick_tree<ll> ans(n); //答えを求めるBIT

//挿入
fw.add(i, 1);
ans.add(i, a[i]);

//削除
fw.add(i, -1);
ans.add(i, -a[i]);

//K番目の何かを求める(二分探索)
auto f = [&](ll x) {
    int res = fw.sum(0, x + 1);
    if(res >= k) return true;
    else return false;
};

ll ok = n;
ll ng = -1;
while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(f(mid)) {
        ok = mid;
    } else {
        ng = mid;
    }
}