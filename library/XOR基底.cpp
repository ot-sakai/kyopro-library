//数列{an}からxor基底を取り出す
//O(n*2^n)
vector<int> base;
for(auto v : a) {
    for(auto e : base) {
        v = min(v, v ^ e);
    }
    if(v > 0) {
        base.push_back(v);
    }
}