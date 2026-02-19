//尺取り法 計算量O(n)
int right = 0;
for(int left = 0; left < n; left++) {
    while(right < n && 条件) {
        right++;
    }

    ans += (right - left);

    if(right == left) right++;
}


//尺取り法 (逆バージョン)
// >=kの場合など
int left = 0;
for(int right = 0; right < n; right++) {
    while(left < right && left < n && 条件) {
        left++;
    }
}