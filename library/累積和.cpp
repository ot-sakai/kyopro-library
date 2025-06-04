//累積和
//前処理 O(n)
vector<ll> sum(n + 1);
sum[0] = 0;
for(int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
}

sum[r] - sum[l];

//二次元 O(n^2)
vector<vector<ll>> sum(n + 1, vector<ll>(n + 1));
sum[0][0] = 0;
sum[0][1] = 0;
sum[1][0] = 0;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
    }
}
sum[c + 1][d + 1] - sum[c + 1][b] - sum[a][d + 1] + sum[a][b];

//三次元 O(n^3)
ll sum[n + 1][n + 1][n + 1];
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            sum[i + 1][j + 1][k + 1] = a[i][j][k];
            //1次元の累積和
            sum[i + 1][j + 1][k + 1] += sum[i][j + 1][k + 1];
            sum[i + 1][j + 1][k + 1] += sum[i + 1][j][k + 1];
            sum[i + 1][j + 1][k + 1] += sum[i + 1][j + 1][k];

            //2次元の累積和(平面)を除去する
            sum[i + 1][j + 1][k + 1] -= sum[i][j][k + 1];
            sum[i + 1][j + 1][k + 1] -= sum[i][j + 1][k];
            sum[i + 1][j + 1][k + 1] -= sum[i + 1][j][k];

            //頂点の重複を追加する
            sum[i + 1][j + 1][k + 1] += sum[i][j][k];
        }
    }
}
total += sum[rx + 1][ry + 1][rz + 1];
//直方体を引く
total -= (sum[lx][ry + 1][rz + 1] + sum[rx + 1][ly][rz + 1] + sum[rx + 1][ry + 1][lz]);
//二重に引かれた分を足す
total += (sum[lx][ly][rz + 1] + sum[lx][ry + 1][lz] + sum[rx + 1][ly][lz]);
//三重に足された分を引く
total -= sum[lx][ly][lz];