//なもりグラフの閉路検出(次数1の頂点を削っていく)
queue<int> que;
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

//dfsでの実装
bool dfs(int v) {
    seen[v] = true; // 行きがけ時に true になる
    for(auto next_v : graph[v]) {
        //if(next_v == previous_v) continue; //逆戻りの場合(無向グラフの場合は必要)
        if(finished[next_v]) continue;

        if(seen[next_v] && !finished[next_v]) return true;

        if(!seen[next_v]) {
            if(dfs(next_v)) return true;
        }
    }

    finished[v] = true; // 帰りがけ時に true になる
    return false;
}