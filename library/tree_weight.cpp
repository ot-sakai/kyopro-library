vector<int> vec; //オイラーツアーの頂点配列
vector<int> ind(n); //各頂点がオイラーツアー配列の何番目に最初に訪れるか
fenwick_tree<ll> fw(2 * n);
vector<int> oud(n); //各頂点がオイラーツアー配列の何番目に最後に訪れるか
vector<vector<pair<int, int>>> graph(n);

auto dfs = [&](auto dfs, int now, int par) -> void {
    ind[now] = vec.size();
    vec.push_back(now);
    for(auto[next_v, cost] : graph[now]) {
        if(next_v == par) continue;

        fw.add(vec.size(), cost);
        dfs(dfs, next_v, now);
        vec.push_back(now);
        fw.add(vec.size(), -cost);
    }
    oud[now] = vec.size();
};

dfs(dfs, 0, -1);

//fw.sum(0, ind[v]); //根から頂点vまでの距離