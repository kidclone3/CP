#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> adj[N];
vector<int> a;
vector<int> cnt(N);
vector<int> deg(N);
void dfs(int next, int root) {
    cnt[next] = 1;
    for(auto &u : adj[next]) {
        if (u == root) continue;
        dfs(u, next);
        cnt[next] += cnt[u];
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int l, r; cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dfs(1, 0);
}