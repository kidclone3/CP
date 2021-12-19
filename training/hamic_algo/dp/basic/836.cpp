#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

vector<string> grid;

void solve(){
    int n = grid.size();
    int dp[n][n];
    FOR(i, n) FOR(j, n) {
        dp[i][j] = grid[i][j] - '0';
        if (i && j) dp[i][j] -= dp[i-1][j-1];
        if (i) dp[i][j] += dp[i-1][j];
        if (j) dp[i][j] += dp[i][j-1];
    }
    // FOR(i, n) FOR(j, n) cout << dp[i][j] << " \n"[j==n-1];
    int maxRect = 0;
    FOR(x1, n) FOR(y1, n) FOR(x2, n) FOR(y2, n) {
        int sumRect = dp[x2][y2];
        if (x1) sumRect -= dp[x1-1][y2];
        if (y1) sumRect -= dp[x2][y1-1];
        if (x1 && y1) sumRect += dp[x1-1][y1-1];
        if (sumRect == abs(x2-x1+1) * abs(y2-y1+1)) maxRect = max(maxRect, sumRect);
    }
    cout << maxRect << "\n";
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        grid.push_back(s);
        FOR(i, s.size() - 1) {
            cin >> s;
            grid.push_back(s);
        }
        solve();
        if (t > 0) cout << "\n";
        grid.clear();
    }
}