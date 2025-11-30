/* LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
    query(u,v): u と v の LCA を求める。計算量 O(logn)
    前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
    vector<vector<int>> parent; // parent[k][u]:= u の 2^k 先の親
    vector<int> dist; // root からの距離
    LCA(const vector<vector<int>> &graph, int root = 0) {init(graph, root);}

    //初期化
    void init(const vector<vector<int>> &graph, int root = 0) {
        int V = graph.size();
        int K = 1;
        while((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(graph, root, -1, 0);
        for(int k = 0; k + 1 < K; k++) {
            for(int v = 0; v < V; v++) {
                if(parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    //根からの距離と1つ先の頂点を求める
    void dfs(const vector<vector<int>> &graph, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for(auto next_v : graph[v]) {
            if(next_v == p) continue;
            dfs(graph, next_v, v, d + 1);
        }
    }

    //頂点uとvの最小共通祖先を求める
    int query(int u, int v) {
        if(dist[u] < dist[v]) swap(u, v); // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for(int k = 0; k < K; k++) {
            if((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if(u == v) return u;
        for(int k = K - 1; k >= 0; k--) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    //任意の2点間(u,v)の距離を求める(O(log n))
    int get_dist(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

    //頂点u,vを結ぶパス上に，ある頂点aが存在するかを判定(O(log n))
    bool is_on_path(int u, int v, int a) {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }
};