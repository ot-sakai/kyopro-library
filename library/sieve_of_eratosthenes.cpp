#define N 2e5
vector<bool> isp(N + 1, true);

//エラトステネスの篩 計算量(O(n)より少し大きい)
void sieve() {
    isp[0] = false;
    isp[1] = false;
    for(int i = 2; i * i <= N; i++) {
        if(isp[i]) {
            for(int j = 2; i * j <= N; j++) {
                isp[i * j] = false;
            }
        }
    }
}