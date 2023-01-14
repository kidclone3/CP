#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int next[26];
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string &s) {
    int v = 0;
    for(char ch: s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf = true;
}
#define ll long long
const ll MOD = 1e9+7;
ll add(const ll &a, const ll &b) {
    return a + b > MOD ? a + b - MOD : a + b;
}

int solve() {
    string s; cin >> s;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        string x; cin >> x;
        add_string(x);
    }
    n = s.size();
    vector<ll> f(n+5, 0);
    f[0] = 1;
    for(int i = 0; i < n; ++i) {
        int v = 0; // root;
        for(int j = i; j < n; ++j) {
            if (trie[v].next[s[j] - 'a'] == -1) break;
            v = trie[v].next[s[j] - 'a'];
            if (trie[v].leaf == true) f[j+1] = add(f[j+1], f[i]);
        }
    }
    // for(int i = 0; i <= n; ++i) cerr << f[i] << " \n"[i == n];
    cout << f[n];
    return 0;
}

int main() {
    // trie version 2;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
