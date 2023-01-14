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
int x; // use to track the farthest node

void dfs_utils(int u, int count, int &max_count) {
    visited[u] = true;
    count++;
    for(auto &v: adj[u]) {
        if (!visited[v]) {
            if (count > max_count) {
                x = v;
                max_count = count;
            }
            dfs_utils(v, count, max_count);
        }
    }
}

void dfs(int node, int &max_count) {
    int count = 0;
    visited.reset();
    dfs_utils(node, count, max_count); 
}

int diameter() {
    int max_count = INT_MIN;
    dfs(1, max_count);
    dfs(x, max_count);
    return max(0, max_count);
}

int solve() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tree_diameter = diameter();
    cout << tree_diameter * 3;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
}