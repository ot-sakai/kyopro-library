#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;
using ld = long double;

//using mint = modint; //mint::set_mod(M);
//using mint = modint998244353;
//using mint = modint1000000007;

template<class T> using pq = priority_queue<T>; //大きい順
template<class T> using pq_g = priority_queue<T, vector<T>, greater<T>>; //小さい順

#define vec_unique(v) v.erase(unique(v.begin(), v.end()), v.end()) //重複削除
#define vec_iota(v) iota(v.begin(), v.end(), 0) //0, 1, 2, 3, ..., n - 1にセット
#define concat(a, b) a.insert(a.end(), b.begin(), b.end())
#define debug(x) cerr << #x << " = " << x << endl
#define maxvalue(array) *max_element(array.begin(), array.end())
#define minvalue(array) *min_element(array.begin(), array.end())
#define sumvalue(array) accumulate(array.begin(), array.end(), 0ll)
#define popcount(x) __builtin_popcountll(x)

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

#define INF 2e18
#define INF2 2e9

int main() {
    
    //cout << fixed << setprecision(15) << << endl;
    return 0;
}