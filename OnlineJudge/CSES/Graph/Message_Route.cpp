#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 1e5+5;
vi adj[N];
vi distances(N, 1e9);
bitset<N> visited;
vi path(N);
int last = -1;
void dijkstra() {
    priority_queue<ii> q;
    distances[1] = 0;
    q.push({0, 1});
    // Xet dinh dau tien: 1.
    while(!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        EACH(it, adj[a]) {
            if (distances[a] + 1 < distances[it]) {
                distances[it] = distances[a]+1;
                path[it] = a;
                q.push({-distances[it], it});
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    FOR(m) {
        int l, r; cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dijkstra();
    path[1] = -1;
    // FOR1(n) cout << path[i] << " \n"[i==n];
    if (!path[n]) cout << "IMPOSSIBLE";
    else {
        vi ans = {n};
        int it = path[n];
        while(it != -1) {
            ans.push_back(it);
            it = path[it];
        }
        cout << ans.size() << "\n"; 
        reverse(all(ans));
        print(ans);
    }
}

int main()
{
    IOS;
    solve();
}