//グリッド回転
void grid_rotate(int type) {
    int n = s.size();
    vector<vector<char>> tmp(n, vector<char>(n));
    if(type == 1) { //左に90度回転
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                tmp[n - 1 - j][i] = s[i][j];
            }
        }
    } else if(type == 2) { //左に180度回転
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                tmp[n - 1 - i][n - 1 - j] = s[i][j];
            }
        }
    } else { //左に270度回転
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                tmp[j][n - 1 - i] = s[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            s[i][j] = tmp[i][j];
        }
    }
}