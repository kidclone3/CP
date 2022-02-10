#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
vector<int> a;
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
    int n; cin >> n;
    a.resize(n+5);
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i]-1 << " ";
    }
    
}