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
#define fi first
#define se second
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

const int maxT = 1005;
int t, w, n;

void solve(){
    vii a(n);
    FOR(n) {
        cin >> a[i].fi >> a[i].se;
    }
    int dp[n+5][maxT];
    memset(dp, 0, sizeof dp);
    FOR(i, 1, n+1, 1) {
        FOR(j, 1, t+1, 1) {
            int dist = 3*w*a[i-1].fi;
            if (dist <= j) {
                dp[i][j] = max(a[i-1].se + dp[i-1][j-dist], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }

    cout << dp[n][t] << "\n";

    vii path;     
    int res = dp[n][t];
    int j = t;
    for(int i = n; i > 0 && res > 0 && j > 0; --i) {
        if (res == dp[i-1][j]) continue;
        else {
            path.push_back(a[i-1]);
            res -= a[i-1].se;
            j -= 3*w*a[i-1].fi;
        }
    }
    cout << path.size() << "\n";
    reverse(all(path));
    EACH(it, path) cout << it.fi << " " << it.se << "\n";
}

int main()
{
    IOS;
    int cnt = 0;
    while(cin >> t) {
        if (cnt) cout << "\n";
        cin >> w >> n;
        solve();
        cnt++;
    }
}