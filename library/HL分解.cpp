struct HLD {
    int n;
    vector<vector<int>> g;
    vector<int> sz, depth, head, in, out, par;
    int timer;

    HLD(int n) : n(n), g(n), sz(n), depth(n), head(n), in(n), out(n), par(n) {}

    // 無向辺を追加
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 根を指定して構築（デフォルトは頂点0）
    void build(int root = 0) {
        timer = 0;
        dfs_sz(root, -1, 0);
        head[root] = root;
        dfs_hld(root, -1);
    }

    void dfs_sz(int v, int p, int d) {
        sz[v] = 1;
        depth[v] = d;
        par[v] = p;
        if (g[v].size() && g[v][0] == p) swap(g[v][0], g[v].back());
        for (auto& to : g[v]) {
            if (to == p) continue;
            dfs_sz(to, v, d + 1);
            sz[v] += sz[to];
            // 部分木のサイズが最大のものを先頭にする（Heavy Edge）
            if (sz[to] > sz[g[v][0]]) swap(to, g[v][0]);
        }
    }

    void dfs_hld(int v, int p) {
        in[v] = timer++;
        for (auto to : g[v]) {
            if (to == p) continue;
            // Heavy Edgeなら現在のheadを引き継ぐ、Light Edgeなら自身を新たなheadとする
            head[to] = (to == g[v][0] ? head[v] : to);
            dfs_hld(to, v);
        }
        out[v] = timer;
    }

    // 頂点 u と v の最小共通祖先 (LCA)
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            u = par[head[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }

    // 頂点 v のセグメント木上のインデックスを取得
    int get_idx(int v) const {
        return in[v];
    }

    // パス u-v に対応するセグメント木上の区間 [l, r) のリストを返す
    // is_edge = true の場合、LCAの頂点を除外する（辺に対するクエリ用）
    vector<pair<int, int>> get_path_intervals(int u, int v, bool is_edge = false) {
        vector<pair<int, int>> res;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res.emplace_back(in[head[u]], in[u] + 1);
            u = par[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        // is_edge が true なら lca(u) のインデックスを +1 して区間から外す
        if (in[u] + is_edge < in[v] + 1) {
            res.emplace_back(in[u] + is_edge, in[v] + 1);
        }
        return res;
    }

    // 頂点 v の部分木に対応するセグメント木上の区間 [l, r) を返す
    // is_edge = true の場合、頂点 v 自身を除外する
    pair<int, int> get_subtree_interval(int v, bool is_edge = false) {
        return {in[v] + is_edge, out[v]};
    }
};