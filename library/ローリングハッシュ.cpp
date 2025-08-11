//検索対象文字列S(n文字)に検索文字列T(m文字)が含めれるかどうか
//時間計算量O(n + m)
// ローリングハッシュ
struct RollingHash {
    static const int base1 = 1007, base2 = 2009;
    static const int mod1 = 1000000007, mod2 = 1000000009;
    vector<long long> hash1, hash2, power1, power2;

    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        power1.assign(n+1, 1);
        power2.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + S[i]) % mod2;
            power1[i+1] = (power1[i] * base1) % mod1;
            power2[i+1] = (power2[i] * base2) % mod2;
        }
    }
    
    // get hash of S[left:right]
    inline pair<long long, long long> get(int l, int r) const {
        long long res1 = hash1[r] - hash1[l] * power1[r-l] % mod1;
        if (res1 < 0) res1 += mod1;
        long long res2 = hash2[r] - hash2[l] * power2[r-l] % mod2;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }
};

int main() {
    string s = "hellohello";
    RollingHash rh(s);

    // s[0..4] = "hello" のハッシュを表示
    cout << "Hash of s[0..5): " << rh.get(0, 5) << endl;

    // s[5..10] = "hello" のハッシュを表示
    cout << "Hash of s[5..10): " << rh.get(5, 10) << endl;

    // 一致するならハッシュも同じ
    if (rh.get(0, 5) == rh.get(5, 10)) {
        cout << "Substrings are equal!" << endl;
    }

    return 0;
}
