// std::uniform_int_distributionを利用した一様乱数生成クラス
class Random_Gen{
    random_device seed_gen;
    mt19937 engine;
    uniform_int_distribution<int64_t> dist;
    public:
        // Constructor [l,r]で生成する値の範囲を指定
        Random_Gen() : engine(seed_gen()) {}
        Random_Gen(int64_t l, int64_t r) : engine(seed_gen()), dist(l,r) {}
        
        // 現在の生成する値の範囲をstd::pairで返す
        pair<int64_t,int64_t> get_range(){
            return make_pair(dist.min(),dist.max());
        }
        // 生成する値の範囲を[l,r]に変更する
        void set_range(int64_t l, int64_t r){
            uniform_int_distribution<int64_t>::param_type Param(l,r);
            dist.param(Param);
        }
        // [l,r]内の一様分布の整数を返す
        int64_t gen(){
            return dist(engine);
        }
        int64_t operator()(){ return gen(); }
};


//使用例
int main(){
    // 1から6までの範囲の一様分布乱数を生成
    Random_Gen Random(1,6);
    /* 以下でも等価
    Random_Gen Random;
    Random.set_range(1,6);
    */
    auto [l,r] = Random.get_range();
    cout << l << " " << r << '\n';
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cout << Random.gen() << " \n"[i+1==n];
        // Random.gen() は Random() と等価
    }
}

//入力例：
/*10*/
//出力例：
/*
1 6
1 6 3 4 5 4 1 3 4 2
*/