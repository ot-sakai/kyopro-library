//1, Unordered map(vector<vector<char>> version)
// カスタムハッシュ関数を定義する構造体
struct VectorVectorCharHash {
    std::size_t operator()(const std::vector<std::vector<char>>& state) const {
        std::size_t seed = 0;
        
        for (const auto& inner_vec : state) {
            for (char c : inner_vec) {
                seed ^= std::hash<char>{}(c) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
        }
        return seed;
    }
};

std::unordered_map<
    std::vector<std::vector<char>>,
    int,
    VectorVectorCharHash
> mp;





//2, Unordered map (vector<string> version)
// カスタムハッシュ関数を定義する構造体
struct VectorStringHash {
    std::size_t operator()(const std::vector<std::string>& vec) const {
        std::size_t seed = 0;
        std::hash<std::string> string_hasher;

        for (const auto& str : vec) {
            std::size_t str_hash = string_hasher(str);
            
            seed ^= str_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

std::unordered_map<
    std::vector<std::string>,
    int,
    VectorStringHash
> mp;






//3, Unorderd map(pair<ll, ll>> version)
// カスタムハッシュ関数を定義する構造体
struct PairLLHash {
    std::size_t operator()(const std::pair<ll, ll>& p) const {
        std::size_t h1 = std::hash<ll>{}(p.first);
        std::size_t h2 = std::hash<ll>{}(p.second);
        
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

std::unordered_map<
    std::pair<ll, ll>,
    int,
    PairLLHash
> mp;






//4, Unorderd map(tuple<ll, ll, ll> version)
// 1. カスタムハッシュ関数の定義
struct TupleLLHash {
    std::size_t operator()(const std::tuple<ll, ll, ll>& t) const {
        std::size_t seed = 0;
        
        // 3つの要素のハッシュ値を順番に組み合わせる
        hash_combine(seed, std::get<0>(t));
        hash_combine(seed, std::get<1>(t));
        hash_combine(seed, std::get<2>(t));

        return seed;
    }
};

std::unordered_map<
    std::tuple<ll, ll, ll>,
    int,
    TupleLLHash 
> mp;






//5, Unorderd map(vector<ll> version)
// カスタムハッシュ関数を定義する構造体
struct VectorLLHash {
    std::size_t operator()(const std::vector<ll>& vec) const {
        std::size_t seed = 0;
        
        std::hash<ll> ll_hasher;

        for (ll value : vec) {
            std::size_t val_hash = ll_hasher(value);
            
            seed ^= val_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};


std::unordered_map<
    std::vector<ll>,
    int,
    VectorLLHash
> mp;