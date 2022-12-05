#include<bits/stdc++.h>
using namespace std;
 
const int N = 2*1e5+5;
vector<int> adj[N];
 
pair<int, int> mx;
 
void dfs(int next, int root, int len) {
    if (len > mx.first) mx = {len, next};
    for(auto &u : adj[next]) {
        if (u == root) continue;
        dfs(u, next, len+1);
    }
}
 
int main() {
    mx = {0,0};
    int n; cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dfs(1, 0, 0);
    dfs(mx.second, 0, 0);
    cout << mx.first;
}