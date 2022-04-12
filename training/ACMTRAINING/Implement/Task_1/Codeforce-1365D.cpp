#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int)(b) : i>(int)(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
        d4y[] = {0, -1, 0, 1},
        d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void bfs(vector<string> &grid, vvb &visited) {

    int n = grid.size();
    int m = grid[0].size();
    queue<ii> q;
    if (grid[n-1][m-1] == '#') return;
    q.push({n-1, m-1});
    visited[n-1][m-1] = true;
    while(!q.empty()) {
        ii curr = q.front();
        q.pop();

        FOR(k, 4) {
            int x = curr.fi + d4x[k];
            int y = curr.se + d4y[k];
            if (0 <= x && x < n && 0 <= y && y < m) {
                if (!visited[x][y] && (grid[x][y] == '.' || grid[x][y] == 'G')) {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }
}

int solve() {
    int n, m; cin >> n >> m;
    vt<string> grid(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    // Neu bon nao gan cong ra nhat => ra luon.
    // FOR(k, 4) {
    //     int x = n-1+d4x[k];
    //     int y = m-1+d4y[k];
    //     if (0 <= x && x < n && 0 <= y && y < m) {
    //         if (grid[x][y] == 'G') {
    //             grid[x][y] = '.'; // Coi nhu da thoat thanh cong.
    //         }
    //         // if (grid[i][j] == '.') grid[i][j] = '#';
    //     }
    // }
    FOR(i, n) FOR(j, m) {
        if (grid[i][j] == 'B') {
            for(int k = 0; k < 4; ++k) {
                int x = i+d4x[k];
                int y = j+d4y[k];
                if (0 <= x && x < n && 0 <= y && y < m) {
                    if (grid[x][y] == 'G') {
                        return 0;
                    }
                    if (grid[x][y] == '.') grid[x][y] = '#';
                }
            }
        }
    }
    // FOR(n) cout << grid[i] << "\n";
    // cout << '\n';
    vvb visited(n, vb(m, 0));
    bfs(grid, visited);
    // cout << visited;
    // FOR(i, n) FOR(j, m) cout << visited[i][j] << " \n"[j == m-1];
    FOR(i, n) FOR(j, m) {
        if (grid[i][j] == 'G' && !visited[i][j]) return 0;
    }
    return 1;
}
int main() {
    IOS;
    int t; cin >> t;
    while(t--)
    cout << (solve() ? "Yes" : "No") << "\n";
    return 0; 
}

