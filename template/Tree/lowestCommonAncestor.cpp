#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
vector<int> g[N];
int n, q; 
int h[N], up[N][20];

void dfs(int u) {
    for (auto v: g[u]) {
        if (v == up[u][0]) continue; // v = ancestor of u
        h[v] = h[u] + 1;
        up[v][0] = u;
        for(int j = 1; j < 20; ++j) {
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v);
    }
}

int lca(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v); // Without lost of generality

        // find ancestor u' of u so h[u'] = h[v]
        int k = h[u] - h[v];
        for(int j = 0; (1<<j) <= k; ++j) {
            if (k >> j & 1) u = up[u][j];
        }
    }
    if (u == v) return u;
    int k = __lg(h[u]);
    for(int j = k; j >= 0; --j) {
        if (up[u][j] != up[v][j]) { // if ancestor 2^j th of u and v is different
            u = up[u][j], v = up[v][j];
        }
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i) {
        int x; cin >> x;
        // g[i].push_back(x);
        // g[x].push_back(i);
        g[i].emplace_back(x);
        g[x].emplace_back(i);
    }
    // for(int i = 0; i < n; ++i) {
    //     cout << "Number " << i << ":\n ";
    //     for(auto &it: g[i]) cout << it << " "; 
    //     cout << "\n";
    // }
    dfs(0);
    for(int i = 0; i < q; ++i) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    } 
    return 0;
}

