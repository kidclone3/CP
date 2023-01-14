#include<bits/stdc++.h>
using namespace std;

// DisjointSet {{{
struct DSU {
    vector<int> lab;

    DSU(int n) : lab(n+1, -1) {}

    int getRoot(int u) {
        if (lab[u] < 0) return u;
        return lab[u] = getRoot(lab[u]);
    }

    bool merge(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }

    bool same_component(int u, int v) {
        return getRoot(u) == getRoot(v);
    }

    int component_size(int u) {
        return -lab[getRoot(u)];
    }
};
// }}}

void solve() { 
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& x : a)
    {
        cin >> x;
        --x;
    }
    DSU dsu(n);
    while (m--) {
        int u, v; cin >> u >> v;
        --u; --v;
        dsu.merge(a[u], a[v]);
    }
    vector<int> f(n, 0);
    for (int i = 0; i < n; ++i) {
    // consider only positions from 0 -> i
    // Recompute:
    // f[j] = max length of LIS ending at value <= j
    for (int j = n-1; j>= 0; --j) {
        if (dsu.same_component(a[i], j)) {
            if (i == 0) {
                f[j] = 1;
            } else if (f[j-1] + 1 > f[i]) {
                f[j] = f[j-1] + 1;
            }
        }
    }
    // 1 update f[j] = max(f[j], f[j-1])
    partial_sum(f.begin(), f.end(), f.begin(),[] (int u, int v) { return u > v? u: v; }) ;
    }
    cout << f.back() << endl;
}
