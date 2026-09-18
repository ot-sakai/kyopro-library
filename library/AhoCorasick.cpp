//AhoCorasick法
struct AhoCorasick {
    struct Node {
        map<int, int> to;
        int suf = 0; //failure関数
        vector<int> match; // マッチした文字列のインデックスを保持
    };

    int n;
    vector<Node> nodes;

    AhoCorasick(const vector<vector<int>>& T) {
        Node init;
        nodes.push_back(init);
        n = T.size();

        //構築
        for(int i = 0; i < n; i++) {
            int now = 0;
            for (int d : T[i]) {
                if(!nodes[now].to.count(d)) {
                    int nx = nodes.size();
                    nodes.push_back(init);
                    nodes[now].to[d] = nx;
                    now = nx;
                } else {
                    now = nodes[now].to[d];
                }
            }
            nodes[now].match.push_back(i);
        }

        //failure関数の遷移先決定
        vector<int> Q;
        for (auto t : nodes[0].to) Q.push_back(t.second);
        for(int i = 0; i < Q.size(); i++){
            int q = Q[i];
            for (auto t : nodes[q].to) {
                Q.push_back(t.second);
                int now = q;
                while(now) {
                    now = nodes[now].suf;
                    if(nodes[now].to.count(t.first)) {
                        nodes[t.second].suf = nodes[now].to[t.first];
                        break;
                    }
                    if(now == 0) break;
                }

                if(auto id : nodes[nodes[t.second].suf].match) {
                    nodes[t.second].match.push_back(id);
                }
            }
        }
    }

    int next(int v, int ch) {
        while(v > 0 && !nodes[v].to.count(ch)) v = nodes[v].suf;
        
        if(nodes[v].to.count(ch)) v = nodes[v].to[ch];
        else v = 0;
        
        return v;
    }
};