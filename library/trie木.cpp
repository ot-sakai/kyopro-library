#include <bits/stdc++.h>
using namespace std;

//Trie木
//何らかの情報と次の文字への遷移(連想配列)を持つ
//ポインタで持つことに注意!!

struct Node {
    //int cnt = 0;
    //bool banned = false;
    //Node* prev;
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