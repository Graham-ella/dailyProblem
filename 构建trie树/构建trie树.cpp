#include "head.h"

class Trie {
private:
    Trie* son[26];
    bool isWord;
public:
    Trie() {
        isWord = false;
        for (int i = 0; i < 26; i++) son[i] = nullptr;
    }//初始化，将孩子节点都初始化为空，标记变量isWord设置为false

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (son[i] != nullptr) delete son[i];
        }
    }//析构函数

    void insert(string word) {
        Trie* root = this;//先找到root节点
        for (char x : word) {
            int cur = x - 'a';
            if (root->son[cur] == nullptr) root->son[cur] = new Trie();//如果没有，新建一个节点
            root = root->son[cur];
        }
        root->isWord = true;
    }//如何插入一个word

    bool search(string word) {
        Trie* root = this;
        for (char x : word) {
            int cur = x - 'a';
            if (root->son[cur] == nullptr) return false;
            root = root->son[cur];
        }
        return root->isWord;
    }

    bool startsWith(string prefix) {
        Trie* root = this;
        for (char x : prefix) {
            int cur = x - 'a';
            if (root->son[cur] == nullptr) return false;
            root = root->son[cur];
        }
        return true;
    }
};


//二维数组版本：
//const int maxn = 1e5 + 50;
//bool vis[maxn];
//int son[maxn][26], idx;
//class Trie {
//public:
//    Trie() {
//        memset(vis, false, sizeof vis);
//        memset(son, 0, sizeof son);
//        idx = 0;
//    }
//
//    void insert(string word) {
//        int p = 0;
//        for (auto x : word) {
//            int u = x - 'a';
//            if (!son[p][u]) son[p][u] = ++idx;
//            p = son[p][u];
//        }
//        vis[p] = true;
//    }
//
//    bool search(string word) {
//        int p = 0;
//        for (auto x : word) {
//            int u = x - 'a';
//            if (!son[p][u]) return false;
//            p = son[p][u];
//        }
//        return vis[p];
//    }
//
//    bool startsWith(string prefix) {
//        int p = 0;
//        for (auto x : prefix) {
//            int u = x - 'a';
//            if (!son[p][u]) return false;
//            p = son[p][u];
//        }
//        return true;
//    }
//};

