//検索対象文字列S(n文字)に検索文字列T(m文字)が含めれるかどうか
//時間計算量O(n + m)
class RollingHash {
private:
    static const long long MOD = 1e9 + 7;  // 大きな素数
    static const long long BASE = 1009;    // 適当な基数

    vector<long long> hash;     // 累積ハッシュ
    vector<long long> power;    // BASEの累乗

public:
    // コンストラクタ: 与えられた文字列のハッシュを前計算
    RollingHash(const string& s) {
        int n = s.size();
        hash.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            hash[i + 1] = (hash[i] * BASE + s[i]) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }
    }

    // 部分文字列 s[l..r) のハッシュを取得
    long long get_hash(int l, int r) const {
        long long res = (hash[r] - hash[l] * power[r - l]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

int main() {
    string s = "hellohello";
    RollingHash rh(s);

    // s[0..4] = "hello" のハッシュを表示
    cout << "Hash of s[0..5): " << rh.get_hash(0, 5) << endl;

    // s[5..10] = "hello" のハッシュを表示
    cout << "Hash of s[5..10): " << rh.get_hash(5, 10) << endl;

    // 一致するならハッシュも同じ
    if (rh.get_hash(0, 5) == rh.get_hash(5, 10)) {
        cout << "Substrings are equal!" << endl;
    }

    return 0;
}