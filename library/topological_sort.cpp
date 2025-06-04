//トポロジカルソート 計算量(O(n + m))
vector<int> topo_sort(const vector<vector<int>> &graph) {
    vector<int> ans;
    vector<int> indegree(n); //入次数
    for(int i = 0; i < n; i++) { //入次数を数える
        for(auto next_v : graph[i]) {
            indegree[next_v]++;
        }
    }
    queue<int> que;
    for(int i = 0; i < n; i++) { //入次数が0の点をキューに入れる
        if(indegree[i] == 0) {
            que.push(i);
        }
    }
    while(!que.empty()) { //bfs
        int now = que.front();
        que.pop();
        ans.push_back(now);
        for(auto next_v : graph[now]) {
            indegree[next_v]--;
            if(indegree[next_v] == 0) {
                que.push(next_v);
            }
        }
    }

    return ans;
}