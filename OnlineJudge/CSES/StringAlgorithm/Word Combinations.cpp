#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;
ll add (const ll &a, const ll &b) {
    return a + b >= MOD ? a+b - MOD : a+b;
}

struct Trie {
    Trie *c[26];
    Trie() {
        for(int i = 0; i < 26; ++i) c[i] = NULL;
    }
    bool isEnd = false;
};

Trie* root = new Trie();

void TrieInsert(const string &s) {
    int n = s.size();
    Trie *p = root;
    for(int i = 0; i < n; ++i) {
        int nxt = s[i] - 'a';
        if (p->c[nxt] == NULL) p->c[nxt] = new Trie();
        p = p->c[nxt];
    }
    p->isEnd = true;
}

int solve() {
    string s; cin >> s;
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i], TrieInsert(a[i]);
    n = s.size();
    vector<ll> f(n+5, 0LL);
    f[0] = 1;
    for(int i = 0; i < n; ++i) {
        Trie *p = root;
        for(int j = i; j < n; ++j) {
            if (p->c[s[j]-'a'] == NULL) break;
            p = p->c[s[j]-'a'];
            if (p->isEnd) f[j+1] = add(f[j+1], f[i]);
        }
    }
    cout << f[n];
    return 0;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
