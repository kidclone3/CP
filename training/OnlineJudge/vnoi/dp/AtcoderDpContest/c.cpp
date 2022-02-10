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

int n;
const int N = 1e5+5;
ll a[N][5];
vector<vl> dp(N, vector<ll> (5, -1));

ll backtrack(int i, int state) {
    if (dp[i][state] != -1) return dp[i][state];
    if (i == n-1) return dp[i][state] = a[i][state];
    ll ans;
    if (state == 0) {
        ll tmp1 = backtrack(i+1, 1);
        ll tmp2 = backtrack(i+1, 2);
        ans = max(tmp1, tmp2);
    }
    else if (state == 1) {
        ll tmp1 = backtrack(i+1, 0);
        ll tmp2 = backtrack(i+1, 2);
        ans = max(tmp1, tmp2);
    }
    else {
        ll tmp1 = backtrack(i+1, 0);
        ll tmp2 = backtrack(i+1, 1);
        ans = max(tmp1, tmp2);
    }
    return dp[i][state] = a[i][state] + ans;
}

void solve(){
    cin >> n;
    // fill(dp, dp+N, -1);
    FOR(n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    backtrack(0, 0);
    backtrack(0, 1);
    backtrack(0, 2);
    cout << max({dp[0][0], dp[0][1], dp[0][2]});
}

int main()
{
    IOS;
    solve();
}