bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int, int>> p(n);
    sort(p.begin(), p.end(), compare);

    // 終了時刻が早い順に見ていく
    int ans = 0;
    int endtime = 0; // 前回の予定の終了時刻
    for(int i = 0; i < n; i++) {
        // 予定 i の開始時刻が、前回終了時刻より早い場合はスキップ
        if(p[i].first < endtime) continue;

        // 予定を採用する
        ans++;
        endtime = p[i].second;
    }
}