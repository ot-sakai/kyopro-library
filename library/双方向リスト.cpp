//双方向リスト
//挿入，削除 O(log n)
//ランダムアクセス O(n)

map<int, int> next; //次の値を紐づけ
map<int, int> prev; //前の値を紐づけ
//初期化
a[0] = 0; //始点
a[n + 1] = -1; //終点
for(int i = 1; i <= n; i++) {
    cin >> a[i];
}
for(int i = 0; i <= n; i++) {
    next[a[i]] = a[i + 1];
    prev[a[i + 1]] = a[i];
}

//挿入 要素xの直後にyを挿入する
int z = next[x];
next[x] = y;
next[y] = z;
prev[z] = y;
prev[y] = x;

//削除 要素xを削除する
int z = prev[x];
int y = next[x];
next[z] = y;
prev[y] = z;
next.erase(x);
prev.erase(x);

//表示
int i = 0;
while(next[i] != -1) {
    cout << next[i] << " ";
    i = next[i];
}
cout << endl;