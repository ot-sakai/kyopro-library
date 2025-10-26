//n以下の回文を全て列挙する
//時間計算量O(√n)
vector<ll> v; //回文を格納する配列
void palindrome_gene(ll n) {
    string s = to_string(n);
    for(int len = 1; len <= s.size(); len++) {
        int half = (len + 1) / 2;
        int left = pow((ll)10, (ll)(half - 1));
        int right = pow((ll)10, (ll)half);

        for(int i = left; i < right; i++) {
            string t = to_string(i);
            string r = t;
            reverse(r.begin(), r.end());

            if(len % 2 != 0) {
                r = r.substr(1);
            }

            string u = t + r;
            ll m = stoll(u);
            if(m > n) return;

            v.push_back(m);
        }
    }
}