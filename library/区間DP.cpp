//区間DP 区間の除去，圧縮，合体などが生じる場合
//計算量 O(n^2), O(n^3)のどちらか
ll rec(int l = 0; int r = n - 1) { //メモ化再帰
    if(l == r) return 0; //要素が1つのみの場合

    if(dp[l][r] != -1) return dp[l][r]; //すでに計算済みならその値を利用

    ll ret = 0; //計算した結果
    //計算
    //dp[l][r] = dp[l + 1][r], dp[l][r - 1] O(n^2)の場合
    /*for(int i = 0; i < n; i++) dp[l][r] = dp[l][i], dp[i + 1][r]
    O(n^3)の場合 */

    return dp[l][r] = ret; //計算結果を返す
}