//尺取り法 計算量O(n)
int right = 0;
for(int left = 0; left < n; left++) {
    while(right < n && 条件) {
        right++;
    }

    ans += (right - left);

    if(right == left) right++;
}