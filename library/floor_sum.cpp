//floor sum [n / i]
//グラフ上の格子点を考える
for(ll i = 1; i * i <= n; i++) {
    sum += (n / i - i) * 2;
    sum++; //重複分加算
}