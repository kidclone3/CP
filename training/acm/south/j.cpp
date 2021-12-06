#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int) (b) : i > (int) (b); i+=(s))
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

void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    FOR(n) cin >> grid[i];
    vector<vi> left(n, vector<int> (m, 0));
    vector<vi> right(n, vector<int> (m, 0));
    vector<vi> up(n, vector<int> (m, 0));
    vector<vi> down(n, vector<int> (m, 0));
    FOR(i, n) FOR(j, m) {
        if (grid[i][j] == '1') {
            left[i][j] = up[i][j] = 1;
            if (j && grid[i][j-1] == '1') left[i][j] += left[i][j-1];
            if (i && grid[i-1][j] == '1') up[i][j] += up[i-1][j];
        }
    }
    FOR(i, n-1, -1, -1) FOR(j, m-1, -1, -1) {
        if (grid[i][j] == '1') {
            right[i][j] = down[i][j] = 1;
            if (j != m-1 && grid[i][j+1] == '1') right[i][j] += right[i][j+1];
            if (i != n-1 && grid[i+1][j] == '1') down[i][j] += down[i+1][j];
        }
    }
    int ans = 0;
    pair<int, int> pos;
    FOR(i, n) FOR(j, m) {
        int r = min({up[i][j], down[i][j], left[i][j], right[i][j]});
        if (r > ans) {
            ans = r;
            pos = {i, j};
        }
    }
    if (ans == 0) cout << "-1";
    else {
        cout << (ans-1)*4+1 << '\n';
        cout << pos.fi+1 << " " << pos.se + 1;
    }
    // cout << "left\n";
    // FOR(i, n) FOR(j, m) cout << left[i][j] << " \n"[j==m-1];
    // cout << "\n";
    // cout << "Right\n";
    // FOR(i, n) FOR(j, m) cout << right[i][j] << " \n"[j==m-1];
    // cout << "\n";
    // cout << "Up\n";
    // FOR(i, n) FOR(j, m) cout << up[i][j] << " \n"[j==m-1];
    // cout << "\n";
    // cout << "Down\n";
    // FOR(i, n) FOR(j, m) cout << down[i][j] << " \n"[j==m-1];
    // cout << "\n";
}

int main()
{
    IOS;
    solve();
}