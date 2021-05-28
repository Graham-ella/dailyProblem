#include "head.h"

class Trie {
private:
	Trie* son[26];
	bool isWord;
public:
	Trie() {
		isWord = false;
		for (int i = 0; i < 26; i++) {
			son[i] = nullptr;
		}
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (son[i] != nullptr) {
				delete(son[i]);
			}
		}
	}

	void insert(string word) {
		Trie* root = this;
		for (char c : word) {
			int cur = c - 'a';
			if (root->son[cur] == nullptr) {
				root->son[cur] = new Trie();
				//创建完新节点后还是要挪下来
				root = root->son[cur];
			}
			else {
				root = root->son[cur];
			}
		}
		root->isWord = true;
	}

	bool search(string word) {
		Trie* root = this;
		for (char c : word) {
			int cur = c - 'a';
			if (root->son[cur] == nullptr) {
				return false;
			}
			else {
				root = root->son[cur];
			}
		}
		//return true;
		//这里写错了，应该返回isWord值，因为可能只是个前缀
		return root->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* root = this;
		for (char c : prefix) {
			int cur = c - 'a';
			if (root->son[cur] == nullptr) {
				return false;
			}
			else {
				root = root->son[cur];
			}
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

