struct query {
    int l;
    int r;
    int id;
};

int n, q, bsize;

bool qcomp(const query &a, const query &b) {
    int al = a.l / bsize;
    int bl = b.l / bsize;
    if(al != bl) return al < bl;

    if(al & 1) return a.r > b.r; //ジグザグにする
    return a.r < b.r;
}

int st, fi;
vector<int> a;
vector<int> cnt;
int res = 0;

void mo_add(int id) {
    cnt[a[id]]++;
    if(cnt[a[id]] == 1) {
        res++;
    }
}

void mo_erase(int id) {
    if(cnt[a[id]] == 1) {
        res--;
    }
    cnt[a[id]]--;
}

ll mo_query(int tst, int tfi) {
    //左端を左に広げる
    while (st > tst) { st--; mo_add(st); }
    //右端を右に広げる
    while (fi < tfi) { mo_add(fi); fi++; }
    //左端を右に縮める
    while (st < tst) { mo_erase(st); st++; }
    //右端を左に縮める
    while (fi > tfi) { fi--; mo_erase(fi); }
    return res;
}



int main() {
    cin >> n >> q;
    bsize = n / sqrt(n);

    vector<query> qv(q);
    for(int i = 0; i < q; i++) {
        cin >> qv[i].l >> qv[i].r;
        qv[i].l--;
        qv[i].id = i;
    }
    sort(qv.begin(), qv.end(), qcomp);

    st = 0;
    fi = 0;
    for(int i = 0; i < q; i++) {
        res[qv[i].id] = mo_query(qv[i].l, qv[i].r);
    }
}