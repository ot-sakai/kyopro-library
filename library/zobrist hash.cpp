//集合同士をO(1)で比較する

// 整数値 x にハッシュ値を割り当てる関数
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator() (uint64_t x) const {
        static const uint64_t FIXED_RANDOM =    
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
} rng;

vector<ll> zobrist_hash(vector<int> v) {
    int n = v.size();
    vector<ll> hash(n + 1, 0);
    set<ll> s; //すでにあるかを確認する

    for(int i = 0; i < n; i++) {
        //すでに含まれている場合は何もしない
        if(s.count(v[i])) {
            hash[i + 1] = hash[i];
            continue;
        }
        s.insert(v[i]);
        hash[i + 1] = hash[i] ^ rng(v[i]);
    }

    return hash;
}