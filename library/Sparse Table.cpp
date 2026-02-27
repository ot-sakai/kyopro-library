//不変な数列の任意の区間に対する最小値・最大値を前処理O(nlogn)、クエリごとO(1)で求めるデータ構造

template<typename T>
class SparseTable {
    vector<vector<T>> table;
    vector<int> logtable;

public:
    SparseTable(const vector<T> &vec) {
        int n = vec.size();
        int max_log = 0;
        while((1 << (max_log + 1)) <= n) max_log++;

        table.assign(max_log + 1, vector<T>(n));

        for(int i = 0; i < n; i++) {
            table[0][i] = vec[i];
        }

        for(int k = 1; k <= max_log; k++) {
            for(int i = 0; i + (1 << k) <= n; i++) {
                table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }

        //ログテーブルの事前計算
        logtable.assign(n + 1, 0);
        for(int i = 2; i <= n; i++) {
            logtable[i] = logtable[i >> 1] + 1;
        }

        //区間[l, r)の最小値を返す
        T query(int l, int r) {
            int k = logtable[r - l];
            return min(table[k][l], table[k][r - (1 << k)]);
        }
    }
};