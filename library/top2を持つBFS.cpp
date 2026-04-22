//TOP2を持つBFS
//開始点を管理することでTOP2を持つようにする

//グラフ
vector<int> dist(n, INF2); //top
vector<int> dist2(n, INF2); //top2
queue<tuple<int, int, int>> que;
vector<int> from(n, -1);
for(int i = 0; i < n; i++) { //開始点
    que.push({i, 0, i});
    dist[i] = 0;
    from[i] = i;
}

while(!que.empty()) {
    auto[v, dis, f] = que.front();
    que.pop();

    int d = dis + 1;

    for(auto next_v : graph[v]) {
        if(dist2[next_v] <= d) continue;

        if(dist[next_v] > d) {
            dist[next_v] = d;
            from[next_v] = f;
            que.push({next_v, d, f});
        } else if(from[next_v] != f) {
            dist2[next_v] = d;
            que.push({next_v, d, f});
        }
    }
}


//color codingを用いたtop2 BFS
auto f = [&](const vector<int> c) -> vector<ll> {
    vector<ll> dist(n, INF);
    queue<ll> que;
    
    for(auto s : c) {
        que.push(s);
        dist[s] = 0;
    }

    while(!que.empty()) {
        auto v = que.front();
        que.pop();

        for(auto next_v : graph[v]) {
            if(dist[next_v] != INF) continue;

            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }

    return dist;
};

vector<ll> ans(ng.size(), INF);
for(int k = 0; k < 20; k++) {
    vector<int> c1;
    vector<int> c2;
    for(auto x : ok) {
        if((x >> k) & 1) {
            c1.push_back(x);
        } else {
            c2.push_back(x);
        }
    }
    auto d1 = f(c1);
    auto d2 = f(c2);
    for(int i = 0; i < ng.size(); i++) {
        int x = ng[i];
        ans[i] = min(ans[i], (ll)d1[x] + d2[x]);
    }
}