//グリッド回転 左に90度回転
void grid_rotate() {
    int n = s.size();
    vector<vector<char>> tmp(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[n - 1 - j][i] = s[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            s[i][j] = tmp[i][j];
        }
    }
}