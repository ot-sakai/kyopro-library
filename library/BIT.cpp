//BIT Binary Indexed Tree フェニック木
//ACLと使い方一緒
template <class T>
struct fenwick_tree {
    int n;
    vector<T> bit;
    
    fenwick_tree(int n = 0) : n(n), bit(n + 1) {
    }

    void add(int i, T x) {
        i++;
        while(i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) {
        T s = 0;
        while(i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    T sum(int a, int b) {
        return sum(b) - sum(a);
    }
};