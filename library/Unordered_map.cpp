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
> hashmp;





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
> hashmp;






//3, Unorderd map(vector<pair<ll, ll>>> version)
// カスタムハッシュ関数を定義する構造体
struct VectorPairLLHash {
    std::size_t operator()(const std::vector<std::pair<ll, ll>>& vec) const {
        std::size_t seed = 0;
        
        std::hash<ll> ll_hasher;

        for (const auto& p : vec) {
            std::size_t h1 = ll_hasher(p.first);
            std::size_t h2 = ll_hasher(p.second);

            std::size_t pair_hash = h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));

            seed ^= pair_hash + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

std::unordered_map<
    std::vector<std::pair<ll, ll>>,
    int,
    VectorPairLLHash
> hashmp;