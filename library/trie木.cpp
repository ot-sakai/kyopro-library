#include <bits/stdc++.h>
using namespace std;

//Trie木
//何らかの情報と次の文字への遷移(連想配列)を持つ
//ポインタで持つことに注意!!

struct Node {
    //int cnt = 0;
    //bool banned = false;
    //Node* prev = nullptr;
    map<char, Node*> to;
};

int main() {
    int n;
    cin >> n;
    //vector<Node*> trie;
    Node root;
    //trie[0] = &root;

    //入力されるn個の文字列をTrie木に挿入
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        Node* now = &root;
        for(auto c : s) {
            if(now->to.count(c)) {
                //trie[i] = now->to[c];
            } else {
                Node* next = new Node();
                now->to[c] = next;
                //trie[i] = next;
            }
            now = now->to[c];
        }
    }

    string path;
    //DFSでTrie木を辞書順に探索
    auto dfs = [&](auto dfs, Node* now) -> void {
        cout << path << endl;
        for(auto[key, next] : now->to) {
            path.push_back(key);
            dfs(dfs, next);
            path.pop_back();
        }
    };
    dfs(dfs, &root);
}




#include <bits/stdc++.h>
using namespace std;

/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
    insert(word): 単語 word を Trie 木に挿入する
    search(word): 単語 word が Trie 木にあるか判定する
    start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
    count(): 挿入した単語の数を返す
    size(): Trie 木の頂点数を返す
    計算量：insert, search ともに O(M)（Mは単語の長さ）
*/
template <int char_size, int base>
struct Trie {
    struct Node {            // 頂点を表す構造体
        vector<int> next;    // 子の頂点番号を格納。存在しなければ-1
        vector<int> accept;  // 末端がこの頂点になる単語の word_id を保存
        int c;               // base からの間隔をint型で表現したもの
        int common;          // いくつの単語がこの頂点を共有しているか
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;  // trie 木本体
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    // 単語の挿入
    void insert(const string &word, int word_id) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ追加
                next_id = (int)nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);
    }
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }

    // 単語とprefixの検索
    bool search(const string &word, bool prefix = false) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) {  // 次の頂点が存在しなければ終了
                return false;
            }
            node_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].accept.size() > 0;
    }

    // prefix を持つ単語が存在するかの検索
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }

    // 挿入した単語の数
    int count() const {
        return (nodes[0].common);
    }
    // Trie木のノード数
    int size() const {
        return ((int)nodes.size());
    }
};

int main() {
    Trie<26, 'A'> trie;
    trie.insert("FIRE");
    cout << trie.search("FIRE") << endl;  // 1 を返す
    cout << trie.search("FI") << endl;    // 0 を返す
    trie.insert("FIREMAN");
    trie.insert("FIREARM");
    trie.insert("FIREWORK");
    trie.insert("ALGO");
    return 0;
}