//ダイクストラ法 計算量O(m log m)
vector<ll> dist(n, INF);
dist[0] = 0;

pq_g<pair<ll, int>> que;
que.push({0, 0});

while(!que.empty()) {
    auto [d, v] = que.top();
    que.pop();
    if(d > dist[v]) continue;

    for(auto [next_v, cost] : graph[v]) {
        ll nc = d + cost;
        if(nc < dist[next_v]) {
            dist[next_v] = nc;
            que.push({dist[next_v], next_v});
        }
    }
}