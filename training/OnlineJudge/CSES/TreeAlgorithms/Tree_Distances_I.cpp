#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
vector<int> in(N), out(N);

// Calculating in .
void dfs1(int u, int parrent) {
    in[u] = 0;
    // traverse to the substress of u
    for(auto &child : adj[u]) {
        if (child == parrent) continue;
        dfs1(child, u);
        in[u] = max(in[u], 1 + in[child]);
    }
    
}

// Calculating out
void dfs2(int u, int parrent) {
    int mx1, mx2;
    mx1 = mx2 = -1;
    // traverse to the substress of u
    for(auto& child : adj[u]) {
        if (child == parrent) continue;
        // Store the longest and the second longest.
        if (in[child] >= mx1){
            mx2 = mx1;
            mx1 = in[child];
        } 
        else if (in[child] > mx2) mx2 = in[child];
    }
    // traverse to the substress of u
    for(auto &child : adj[u]) {
        if (child == parrent) continue;
        // Find the longest when approach to child.
        // if 2 longest equal together => ok
        // but in case there is only one, this command can except that.
        int longest = mx1;
        if (mx1 == in[child]) longest = mx2;
        out[child] = 1 + max(out[u], 1 + longest);

        // dfs on the child of child...
        dfs2(child, u);
    }
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int l, r; cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) cout << max(in[i], out[i]) << " \n"[i==n];
    // for(int i = 1; i <= n; ++i) cout << out[i] << " \n"[i==n];
}