struct node {
    int child[26];
    int cnt;
};

struct Trie {
    vector<node> nodes;
    node init;
    Trie() {
        for(int i = 0; i < 26; i++) {
            init.child[i] = -1;
        }

        init.cnt = 0;
        nodes.push_back(init);
    }

    void insert(const string &s) {
        int now = 0;
        nodes[now].cnt++;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if(nodes[now].child[c] == -1) {
                nodes[now].child[c] = nodes.size();
                nodes.push_back(init);
            }
            now = nodes[now].child[c];
            nodes[now].cnt++;
        }
    }

    ll query(const string &s) {
        ll res = 0;
        int now = 0;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            now = nodes[now].child[c];
            if(nodes[now].cnt == 1) {
                break;
            }
            res++;
        }

        return res;
    }
};




struct node {
    int child[26];
    bool flag;
    int cnt;
    int parent;
};

struct trie {
    vector<node> nodes;
    node init;
    ll ans = 0;
    trie() {
        for(int i = 0; i < 26; i++) init.child[i] = -1;
        init.flag = false;
        init.cnt = 0;
        init.parent = -1;
        nodes.push_back(init);
    }

    void insert1(const string &s) {
        int now = 0; //頂点0(根)からスタート
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if(nodes[now].child[c] == -1) {
                nodes[now].child[c] = nodes.size();
                nodes.push_back(init);
                nodes.back().parent = now; //追加したばかりの末尾要素の親
            }
            now = nodes[now].child[c];

            if(nodes[now].flag) {
                return;
            }
        }

        nodes[now].flag = true;
        int minus = nodes[now].cnt;
        ans -= minus;

        int p = now;
        while(p != -1) {
            nodes[p].cnt -= minus;
            p = nodes[p].parent;
        }
    }

    void insert2(const string &s) {
        int now = 0;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if(nodes[now].child[c] == -1) {
                nodes[now].child[c] = nodes.size();
                nodes.push_back(init);
                nodes.back().parent = now;
            }
            now = nodes[now].child[c];

            if(nodes[now].flag) {
                return;
            }
        }

        int p = now;
        while(p != -1) {
            nodes[p].cnt++;
            p = nodes[p].parent;
        }

        ans++;
    }
};



struct node {
    map<int, int> child;
    vector<int> vec;
};

map<int, int> mp; //xとノード番号の結びつけ

struct Trie {
    vector<node> nodes;
    node init;
    Trie() {
        nodes.push_back(init);
        mp[0] = 0;
    }

    void insert(const int &x, const int &y, const int &id) {
        int now = mp[x];
        if(!nodes[now].child.count(y)) {
            nodes[now].child[y] = nodes.size();
            nodes.push_back(init);
        }
        now = nodes[now].child[y];
        nodes[now].vec.push_back(id);
        mp[id] = now;
    }

    vector<int> ans;
    void dfs(int v) {
        sort(nodes[v].vec.begin(), nodes[v].vec.end());
        for(auto a : nodes[v].vec) ans.push_back(a);

        for(auto[num, val] : nodes[v].child) {
            dfs(val);
        }

        return;
    }
};