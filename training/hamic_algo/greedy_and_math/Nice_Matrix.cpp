#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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
void solve();
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
}
void solve() {
    int n, m;
    cin >> n >> m;
    int nn = n, mm = m;
    if (n&1) nn += 1;
    if (m&1) mm += 1;
    vector<vector<ll>> a(n, vector<ll>(m));
    FOR(n) {
        FOR(j, m) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;

    FOR(i, 0, nn/2) {
        FOR(j, 0, mm/2) {
            ll med[4];
            med[0] = a[i][j];
            med[1] = a[n-i-1][m-j-1];
            med[2] = a[n-i-1][j];
            med[3] = a[i][m-j-1];
            sort(med, med+4);
            ll mean = (med[1] + med[2]) / 2;
            // ll mean = a[i][j] + a[n-i-1][m-j-1] + a[n-i-1][j] + a[i][m-j-1];
            // mean /= 4;
            ll tmp = abs(a[i][j] - mean) + abs(a[n-i-1][m-j-1] - mean) + abs(a[n-i-1][j] - mean) + abs(a[i][m-j-1] - mean);
            if (i == n-i-1 || j == m-j-1) {
                ans += tmp/2;
            }
            else ans += tmp;
        }
    }
    cout << ans << '\n';
}
