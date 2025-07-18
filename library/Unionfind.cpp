/* UnionFind：素集合系管理の構造体(union by size)
    same(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    merge(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
    size(x): x を含む集合の要素数。
*/
struct UnionFind {
    vector<int> sz, parents;
    //vector<int> minval;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        sz.resize(n, 0);
        parents.resize(n, 0);
        //minval.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        sz[x] = 1;
        //minval[x] = x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    void merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        parents[y] = x;
        sz[x] += sz[y];
        //minval[x] = min(minval[x], minval[y]);
        return;
    }

    /*
    int get_min(int x) {
        return minval[leader(x)];
    }
    */

    int leader(int x) {
        if (x != parents[x]) {
            parents[x] = leader(parents[x]);
        }
        return parents[x];
    }
    int size(int x) { return sz[leader(x)]; }
};