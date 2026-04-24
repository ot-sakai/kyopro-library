template< typename G >
struct HeavyLightDecomposition {
    G &g;
    vector< int > sz, in, out, head, rev, par;

    HeavyLightDecomposition(G &g) :
        g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {}

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        sz[idx] = 1;
        if(g[idx].size() && g[idx][0] == p) swap(g[idx][0], g[idx].back());
        for(auto &to : g[idx]) {
            if(to == p) continue;
            dfs_sz(to, idx);
            sz[idx] += sz[to];
            if(sz[g[idx][0]] < sz[to]) swap(g[idx][0], to);
        }
    }

    void dfs_hld(int idx, int p, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for(auto &to : g[idx]) {
            if(to == p) continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times);
        }
        out[idx] = times;
    }

    void build(int root = 0) {
        dfs_sz(root, -1);
        int t = 0;
        head[root] = root; // headの初期化を確実に
        dfs_hld(root, -1, t);
    }

    // 頂点vのデータ構造上での位置を返す
    int get_id(int v) const { return in[v]; }

    // --- ここからデータ構造との連携用改造 ---

    // パス更新 (SegTree / BIT用)
    // q: (l, r) => void, 例: [&](int l, int r){ seg.update(l, r, x); }
    template< typename Q >
    void path_update(int u, int v, const Q &q, bool edge = false) {
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }

    // パスクエリ (SegTree / BIT用)
    // ti: 単位元
    // q: (l, r) => T, 例: [&](int l, int r){ return seg.query(l, r); }
    // f: (T, T) => T, 例: [&](ll a, ll b){ return a + b; }
    template< typename T, typename Q, typename F >
    T path_query(int u, int v, const T &ti, const Q &q, const F &f, bool edge = false) {
        T l = ti, r = ti;
        for(;; v = par[head[v]]) {
            if(in[u] > in[v]) swap(u, v), swap(l, r);
            if(head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
    }

    // 部分木クエリ
    template< typename Q >
    void subtree_update(int v, const Q &q, bool edge = false) {
        q(in[v] + edge, out[v]);
    }

    template< typename T, typename Q >
    T subtree_query(int v, const Q &q, bool edge = false) {
        return q(in[v] + edge, out[v]);
    }
};