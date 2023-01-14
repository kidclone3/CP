// #include<bits/stdc++.h>
#include<iostream>
#include<bitset>
#include<climits>
#include<vector>
using namespace std;

const int N = 3e5+5;
bitset<N> visited;
vector<int> adj[N];
int n;

int dfs(int u) {
    visited[u] = true;
    int height = 1;
    for(auto &v : adj[u]) {
        if (!visited[v])
    }
}

int solve() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
}