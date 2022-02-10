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
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int main()
{
    IOS;
    solve();
}
ll divide(ll a, ll b, ll c) {
    ll div = __gcd(a, b);
    a /= div;
    b /= div;
    c /= b;
    return a * c;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll> (n, 0LL)) ;
    vector<ll> ans;
    FOR(i, n) {
        FOR(j, n) {
            cin >> a[i][j];
        }
    }
    FOR(i, n) {
        ll tmp = divide(a[i][(i+1) % n], a[(i+1) % n][(i+2) % n], a[i][(i+2) % n]);
        ans.pb(sqrt(tmp));
    }
    print(ans);
}
