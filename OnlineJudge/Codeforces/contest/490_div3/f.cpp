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

const int N = 550, K = 15;
int dp[N][N*K];

void solve(){
    int n, k; cin >> n >> k;
    vi h(k+1, 0);
    map<int, int> c, f;
    FOR(k*n) {
        int x; cin >> x;
        c[x]++;
    }
    FOR(n) {
        int x; cin >> x;
        f[x]++;
    }
    FOR1(k) {
        cin >> h[i];
    }
    FOR(n+1) {
        FOR(j, 0, k*n+1) {
            FOR(curr, 0, k+1) {
                dp[i+1][j+curr] = max(dp[i+1][j+curr], dp[i][j]+h[curr]);
            }
        }
    }
    // printPair(f);
    int ans = 0;
    FOR(i, 1, (int) 1e5+1) {
        ans += dp[f[i]][c[i]];
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
}