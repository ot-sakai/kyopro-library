//なもりグラフの閉路検出(次数1の頂点を削っていく)
queue<int> que;
vector<bool> namori(n, true);
for(int i = 0; i < n; i++) {
    if(deg[i] == 1) {
        que.push(i);
        namori[i] = false;
        deg[i]--;
    }
}

while(!que.empty()) {
    int v = que.front();
    que.pop();
    for(auto next_v : graph[v]) {
        if(!namori[next_v]) continue;

        deg[next_v]--;
        if(deg[next_v] == 1) {
            namori[next_v] = false;
            que.push(next_v);
        }
    }
}

//無向グラフ → Unionfindが一番簡単

//BFSやDFSでもできる

//dfsでの実装(有向グラフ)
bool dfs(int v) {
    seen[v] = true; // 行きがけ時に true になる
    for(auto next_v : graph[v]) {
        if(finished[next_v]) continue;

        if(seen[next_v] && !finished[next_v]) return true;

        if(!seen[next_v]) {
            if(dfs(next_v)) return true;
        }
    }

    finished[v] = true; // 帰りがけ時に true になる
    return false;
}


//dfsでの実装(無向グラフ)
bool dfs(int v, int previous_v) {
    seen[v] = true;
    for(auto next_v : graph[v]) {
        if(next_v == previous_v) continue; //逆戻りの場合

        if(seen[next_v]) return true;

        if(!seen[next_v]) {
            if(dfs(next_v, v)) return true;
        }
    }

    return false;
}


//functional graphの閉路検出
vector<int> detect_cycle(const vector<vector<int>> &graph) {
    int n = graph.size();
    //頂点を1つ好きに選んで，N回移動する
    //→必ず閉路上の頂点に着く
    int v = 0;
    for(int i = 0; i < n; i++) v = graph[v].back();

    //得られた頂点から出発してサイクルを検出する
    vector<int> res;
    int start = v;
    do {
        res.push_back(v);
        v = graph[v].back();
    } while(v != start);

    return res;
}