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

int MAXN = 400;

void solve(){
    int n; cin >> n;
    vl a(n), p(n);
    FOR(n) cin >> a[i];
    FOR(n) {
        if (i) p[i] = p[i-1] + a[i];
        else p[i] = a[i];
    }
    auto query = [&](int l, int r) -> ll {
        return p[r] - (l == 0 ? 0 : p[l-1]) ;
    };
    ll dp[MAXN][MAXN];
    FOR(n-1) dp[i][i+1] = a[i] + a[i+1];
    FOR(n) dp[i][i] = 0;
    FOR(i, n-1, -1, -1) {
        FOR(j, i+2, n) {
            ll best = 1e18;
            FOR(k, i, j) {
                best = min(best, dp[i][k] + dp[k+1][j]);
            }
            dp[i][j] = query(i, j) + best;
        }
    }
    cout << dp[0][n-1] << "\n";
}

int main()
{
    IOS;
    solve();
}