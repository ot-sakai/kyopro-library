//2次元imos法
vector<vector<int>> grid(h + 1, vector<int>(w + 1));
grid[lx][ly]++;
grid[rx][ly]--;
grid[lx][ry]--;
grid[rx][ry]++;

//横方向
for(int x = 0; x <= h; x++) {
    for(int y = 0; y < w; y++) {
        grid[x][y + 1] += grid[x][y];
    }
}

//縦方向
for(int y = 0; y <= w; y++) {
    for(int x = 0; x < h; x++) {
        grid[x + 1][y] += grid[x][y];
    }
}