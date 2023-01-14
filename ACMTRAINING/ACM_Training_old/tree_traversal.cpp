#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
vector<int> a;
// counting node of the root.
vector<int> cnt(N);

void dfs(int next, int root) {
    cnt[next] = 1;
    for(auto &u : adj[next]) {
        if (u == root) continue;
        dfs(u, next);
        cnt[next] += cnt[u];
    }
}

int main() {
    int n; 
    cin >> n;
    a.resize(n+5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dfs(1, 0);
    for (int i = 1; i < n+1; i++)
    {
        cout << cnt[i] << " ";
    }
    
}