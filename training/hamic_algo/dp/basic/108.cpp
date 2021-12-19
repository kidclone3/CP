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

void solve(){
    int n; cin >> n;
    vector<vi> a(n, vi (n)), dp(n, vi(n, 0));
    int maxRect = INT_MIN;
    FOR(n) FOR(j, n) {
        cin >> a[i][j]; 
        dp[i][j] = a[i][j];
        if (j) dp[i][j] += dp[i][j-1];
    }
    // Rubbish, we will use kadane
    // FOR(x1, n) FOR(y1, n) FOR(x2, x1, n) FOR(y2, y1, n) {
    //     int subRect = dp[x2][y2];
    //     if (x1) subRect -= dp[x1-1][y2];
    //     if (y1) subRect -= dp[x2][y1-1];
    //     if (x1 && y1) subRect += dp[x1-1][y1-1];
    //     maxRect = max(maxRect, subRect);
    // }

    auto query = [&] (int row, int left, int right) -> int {
        return dp[row][right] - (left ? dp[row][left-1] : 0);
    };
    FOR(left, n) {
        FOR(right, left, n) {
            int subRect = 0;
            int maxSubRect = INT_MIN;
            FOR(i, n) {
                subRect += query(i, left, right);
                maxSubRect = max(maxSubRect, subRect);
                subRect = max(subRect, 0);
            }
            maxRect = max(maxRect, maxSubRect);
        }
    }
    cout << maxRect << "\n";
}

int main()
{
    IOS;
    solve();
}