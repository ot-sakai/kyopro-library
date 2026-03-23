//尺取り法 計算量O(n)
//半閉区間[,)
int right = 0;
for(int left = 0; left < n; left++) {
    while(right < n) {
        if(条件) {
            right++;
        } else {
            break;
        }
    }

    ans += (right - left);

    if(right == left) right++;
}