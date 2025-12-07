set<pair<ll, ll>> st;
//番兵として，[-INF, -INF) [INF, INF)をsetの中に入れておく
st.insert({-INF, -INF});
st.insert({INF, INF});
//[x, y)をマージ
auto iter = st.lower_bound({x, y});
iter--;

// 今見ている区間の左端が他の区間と被っていたらマージする
// 右側の条件の等号は場面によって変わることがある
// [3,4),[4,5) を [3,5)と扱うかどうか(扱うなら等号がつく)
if(iter->first <= x && x <= iter->second) {
    x = min(x, iter->first);
    y = max(y, iter->second);
    st.erase(iter);
}

iter = st.lower_bound({x, y});
while(true) {
    if(x <= iter->first && iter->first <= y) {
        y = max(y, iter->second);
        iter = st.erase(iter); // 削除された要素の次を指すイテレータを返す
    } else break;
}
st.insert({x, y});