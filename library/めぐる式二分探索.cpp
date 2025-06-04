bool f() {

}

//めぐる式二分探索 計算量O(log n)
ll ok = ;
ll ng = ;
while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(f(mid)) {
        ok = mid;
    } else {
        ng = mid;
    }
}

cout << ok << endl;