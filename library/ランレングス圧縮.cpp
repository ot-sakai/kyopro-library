vector<pair<char, int>> v;
for(int i = 0; i < n; i++) {
    if(s[i] == '0') {
        if(v.empty() || v.back().first == '1') {
            v.push_back({'0', 1});
        } else {
            v.back().second++;
        }
    } else {
        if(v.empty() || v.back().first == '0') {
            v.push_back({'1', 1});
        } else {
            v.back().second++;
        }
    }
}