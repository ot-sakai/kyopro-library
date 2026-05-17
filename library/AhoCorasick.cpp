struct AhoCorasick {
    struct Node {
        std::map<int, int> to;
        int suf = 0;
        int par = 0;
        vector<int> match;// マッチした文字列のインデックスを保持
    };

    int N;
    std::vector<Node> V;

    AhoCorasick(const std::vector<std::vector<int>>& T) {
        V.push_back(Node());
        N = T.size();

        for(int i=0; i<N; i++) {
            int p = 0;
            for (int d : T[i]) {
                auto it = V[p].to.find(d);
                if (it == V[p].to.end()) {
                    int nx = V.size();
                    V.push_back(Node());
                    it = V[p].to.emplace(d, nx).first;
                    V[nx].par = p;
                    p = nx;
                } else {
                    p = it->second;
                }
            }
            V[p].match.push_back(i);
        }

        std::vector<int> Q;
        for (auto t : V[0].to) Q.push_back(t.second);
        for(int i=0; i<int(Q.size()); i++){
            int q = Q[i];
            for (auto t : V[q].to) {
                Q.push_back(t.second);
                int p = q;
                while (p) {
                    p = V[p].suf;
                    auto it = V[p].to.find(t.first);
                    if(it != V[p].to.end()){
                        V[t.second].suf = it->second;
                        break;
                    }
                    if(p == 0) break;
                }

                for(auto id : V[V[t.second].suf].match) {
                    V[t.second].match.push_back(id);
                }
            }
        }
    }

    int next(int v, int ch) {
        while (v > 0 && V[v].to.count(ch) == 0) v = V[v].suf;
        if(V[v].to.count(ch)) v = V[v].to[ch];
        else v = 0;
        
        return v;
    }
};