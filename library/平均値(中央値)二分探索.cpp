//平均値二分探索
//x 1 ,…,x n  の平均値が K 以上 ⇔ (x 1​ −K)+⋯+(x n −K) が 0 以上
ld ok = 0.0;
ld ng = INF;
for(int i = 0; i < 100; i++) {
    ld mid = (ok + ng) / 2;
    if(f(mid)) {
        ok = mid;
    } else {
        ng = mid;
    }
}


//中央値二分探索
//x 1 ,…,x n  の中央値が K 以上 ⇔ x i のうち K 以上のものの個数が K 未満のものの個数より多い
ll ok = 0;
ll ng = INF;
while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(f(mid)) {
        ok = mid;
    } else {
        ng = mid;
    }
}
