// https://codeforces.com/problemset/problem/1365/D
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
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
#define FOR1(i, n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
const int d4x[] = {-1, 0, 0, 1};
const int d4y[] = {0, -1, 1, 0};
int n, m;
vector<vector<char>> a;
vector<vector<bool>> visited;
bool solve();
bool isValid(int row, int col) {
    return row > 0 && row <= n && col >0 && col <= m;
}
void bfs() {
    visited.resize(n+2);
    visited.assign(n+2, vector<bool> (m+2, 0));
    if (a[n][m]=='#') return;
    queue<pair<int, int>> que;
    que.push({n,m});
    visited[n][m] = 1;
    while (!que.empty()) {
        auto curr = que.front();
        que.pop();
        FOR(4) {
            int row = curr.first + d4x[i];
            int col = curr.second + d4y[i];
            if (isValid(row, col) && a[row][col]!='#' && !visited[row][col]) {
                que.push({row, col});
                visited[row][col] = 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}
bool solve() {
    cin >> n >> m;
    a.resize(n+2);
    a.assign(n+2, vector<char>(m+2, '#'));
    vector<pair<int, int>> bad, good;
    FOR1(i, n) {
        FOR1(j, m) {
            cin >> a[i][j];
            if (a[i][j] == 'B') bad.pb({i, j});
            if (a[i][j] == 'G') good.pb({i, j});
        }
    }
    // EACH(it, a) {
    //     print(it);
    // }
    EACH(it, bad) {
        if (it == make_pair(n, m)) return false;
        FOR(i, 4) {
            int row = it.first + d4x[i];
            int col = it.second + d4y[i];
            if (a[row][col] == '.') {
                a[row][col] = '#';
            }
            if (a[row][col] == 'G') return false;
        }
    }
    bfs();
    FOR1(i, n) {
        FOR1(j, m) {
            if (a[i][j] == 'G' && !visited[i][j]) return false;
            if (a[i][j] == 'B' && visited[i][j]) return false;
        }
    }
    return true;
    // EACH(it, a) {
    //     print(it);
    // }
    
    return true;
}
