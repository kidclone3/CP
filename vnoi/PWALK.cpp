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
const int N = 1e3+5;
const ll inf = 1e9;
long long distances[N];
bool processed[N];
int n;
void solve();
void dijkstra(int x);
priority_queue<pair<ll, int>> q;
vector<pair<int, ll>> adj[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    int queries;
    cin >> n >> queries;
    FOR(i, n-1) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    } 
    FOR(i, queries) {
        int l, r;
        cin >> l >> r;
        dijkstra(l);
        cout << distances[r] << "\n";
    }

}
void dijkstra(int x) {
    FOR1(i, n) {
        distances[i] = inf;
        processed[i] = 0;
    }
    distances[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first;
            ll w = u.second;
            if (distances[a] + w < distances[b]) {
                distances[b] = distances[a] + w;
                q.push({-distances[b], b});
            }
        }
    }

}