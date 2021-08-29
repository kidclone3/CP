// https://oj.vnoi.info/problem/ads
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
const int N = 2000+5;
set<int> a[N];
bool visited[N];

void dfs(int v);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    int n, m;
    cin >> n >> m;
    FOR(i, m) {
        int l, r;
        cin >> l >> r;
        a[l].insert(r);
        a[r].insert(l);
    }
    int tplt = 0;
    FOR1(i, n) {
        if (!visited[i]) ++tplt, dfs(i);
        
    }
    cout << m - n + tplt;
}
void dfs(int u) {
    visited[u] = 1;
    // a[u]: Danh sach cac dinh ke vs dinh u.
    EACH(it, a[u]) {
        int v = it;
        if (!visited[v]) {
            dfs(v);
        }    
    }
}