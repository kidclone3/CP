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
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cerr << it << " ";
    }
    cerr << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cerr << "(" << it.first << ", " << it.second <<") ";
    }
    cerr << "\n";
};
int dp[500+5][500+5];
const int N = 500;
// const int N = 10;
const int inf = 0x3f3f3f3f;
// int preCal2(int x, int y) {
//     if (x == 1 || y == 1) {
//         return dp[x][y] = max(x, y) - 1;
//     }
//     else if (x == y) return dp[x][y] = 0;
//     else {
//         for (int i = 1; i <= min(x, y); ++i) {
//             if (dp[x][y] != inf) return dp[x][y];
//             else dp[x][y] = min(preCal2(i, y) + preCal2(x-i, y), preCal2(x, i) + preCal2(x, y-i)) + 1;
//         }
//         return dp[x][y];
//     }
// }
int solve() {
    int x, y; cin >> x >> y;
    FOR(i, 0, N+1)
        FOR(j, 0, N+1) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 0; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                for (int k = 0; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
    cout << dp[x][y];
    return 0;
}
int main() {
    IOS;
    memset(dp, 0x3f, sizeof dp);
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#else
	// online submission
#endif
    solve();
    return 0; 
}

