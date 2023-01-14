#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
const int Q = 3e5+5;
int n;
vector<int> g[N];
int h[N], up[N][20];

void dfs(int u) {
    for (auto &v: g[u]) {
        if (v == up[u][0]) continue; // v is ancestor of u
        h[v] = h[u] + 1; // height
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

int dfs_up (int u, int end, int energy) {
    if (energy == 0) return u;
    return dfs_up(up[u][0], end, energy-1);
}

// int dfs_down(int u, int end, int energy) {
//     if (energy == 0) return u;

// }

int solve() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int q; cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int t_lca = lca(a, b);
        int ans;
        if (t_lca == b) {
            int i_dist = abs(h[a] - h[b]) + 1;
            ans = dfs_up(a, b, min(c, i_dist));
        }
        else if (t_lca == a) {
            // Travel from b to a, with
            int i_dist = abs(h[a] - h[b]) + 1;
            if (c >= i_dist) ans = b; 
            else {
                ans = dfs_up(b, a, i_dist - c - 1);
            }
        } else {
            int i_dist_left = abs(h[a] - h[t_lca]);
            if (c >= i_dist_left) {
                c -= i_dist_left;
            } else {
                ans = dfs_up(a, t_lca, c);
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}