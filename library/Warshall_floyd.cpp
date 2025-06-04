//ワ―シャルフロイド法 計算量O(n^3)
void warshall_floyd(vector<vector<ll>> &dist) {
    int n = dist.size();
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

vector<vector<ll>> dist(n, INF);

for(int i = 0; i < n; i++) {
    dist[i][i] = 0;
}