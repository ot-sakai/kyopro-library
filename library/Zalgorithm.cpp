//Z algorithm
//文字列 S=s[0] + s[1] + s[2] + ... + s[s.size() - 1]
//文字列 s[i] + s[i + 1] + s[i + 2] + ... + s[s.size() - 1]
//の最長共通接頭辞の長さを求める
//計算量O(s.size())

int n = s.size();
vector<int> z(n);
int i = 1;
int j = 0;
while(i < n) {
    while(i + j < n && s[j] == s[i + j]) j++;
    z[i] = j;

    if(j == 0) {
        i++;
        continue;
    }
    int k = 1;
    while(k < j && k + z[k] < j) {
        z[i + k] = z[k];
        k++;
    }
    i += k;
    j -= k;
}
