#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *child[26];
    int cnt;
    TrieNode() {
        for(int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
        cnt = 0;
    }
};

TrieNode* root = new TrieNode();

void TrieInsert(const string &s) {
    int n = s.size();
    TrieNode* p = root;
    for (int i = 0; i < n; ++i) {
        int nxt = s[i] - 'a';
        if (p->child[nxt] == NULL) {
            p->child[nxt] = new TrieNode();
        }
        p = p->child[nxt];
    }
    if (p->child)
    ++p->cnt;
}

bool TrieFind(const string &s) {
    int n = s.size();
    TrieNode*p = root;
    for(int i = 0; i < n; ++i) {
        int nxt = s[i] - 'a';
        if (p->child[nxt] == NULL) return false;
        p = p->child[nxt];
    }
    return p->nxt > 0;
}

int main() {

}