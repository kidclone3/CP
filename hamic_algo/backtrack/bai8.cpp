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
        cout << it << "\n";
    }
    cout << "\n";
};
void solve();
int n;
set<vector<string>> ans;
bool inside(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void out(vector<string> grid) {
    if (n >= 2 && grid[1][0] == '1')
        ans.insert(grid);
}
void dfs(int k, int x, int y, vector<string> &grid) {
    if (k == n) {
        out(grid);
    }
    if (grid[x][y] == '0') {
        grid[x][y] = '1';
        if (inside(x+1, y)) {
            dfs(k+1, x+1, y, grid);
        }
        if (inside(x, y+1)) {
            dfs(k+1, x, y+1, grid);
        }
        grid[x][y] = '0';
    }
}
int main()
{
    IOS;
    solve();
}
void solve() {
    cin >> n;
    vector<string> grid(n, string(n, '0'));
    dfs(0, 0, 0, grid);
    cout << ans.size() << "\n";
    EACH(it, ans) {
        print(it);
    }
}
