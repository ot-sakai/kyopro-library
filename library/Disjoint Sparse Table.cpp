//DisjointSparseTable(v, f): 配列 v で初期化する. f は半群をマージする二項演算である.
//fold(l, r): 区間 [l,r) を演算した結果を返す.
//計算量 前処理O(n log n) クエリO(1)

/**
 * @brief Disjoint-Sparse-Table
 *
 */
template <typename Semigroup, typename F>
struct DisjointSparseTable {
  const F f;
  vector<vector<Semigroup> > st;
  vector<int> lookup;

  DisjointSparseTable(const vector<Semigroup>& v, const F& f) : f(f) {
    int b = 0;
    while ((1 << b) <= v.size()) ++b;
    st.resize(b, vector<Semigroup>(v.size(), Semigroup()));
    for (int i = 0; i < v.size(); i++) st[0][i] = v[i];
    for (int i = 1; i < b; i++) {
      int shift = 1 << i;
      for (int j = 0; j < v.size(); j += shift << 1) {
        int t = min(j + shift, (int)v.size());
        st[i][t - 1] = v[t - 1];
        for (int k = t - 2; k >= j; k--) st[i][k] = f(v[k], st[i][k + 1]);
        if (v.size() <= t) break;
        st[i][t] = v[t];
        int r = min(t + shift, (int)v.size());
        for (int k = t + 1; k < r; k++) st[i][k] = f(st[i][k - 1], v[k]);
      }
    }
    lookup.resize(1 << b);
    for (int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  Semigroup fold(int l, int r) {
    if (l >= --r) return st[0][l];
    int p = lookup[l ^ r];
    return f(st[p][l], st[p][r]);
  }
};

template <typename SemiGroup, typename F>
DisjointSparseTable<SemiGroup, F> get_disjoint_sparse_table(
    const vector<SemiGroup>& v, const F& f) {
  return {v, f};
}


int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int > A(N);
  cin >> A;
  auto f = [](int a, int b) { return min(a, b); };
  auto st = get_disjoint_sparse_table(A, f);
  while(Q--) {
    int l, r;
    cin >> l >> r;
    cout << st.fold(l, r) << "\n";
  }
}