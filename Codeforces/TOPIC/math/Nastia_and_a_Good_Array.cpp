// https://codeforces.com/contest/1521/problem/B
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
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n;
    ll mx = 1e9 + 7;
    ll mx2 = 1073676287;
    cin >> n;    
    vector<ll> a(n);
    FOR(n) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }
    vector<ll> b = a;
    vector<tuple<ll, ll, ll, ll>> ans;
    if (__gcd(b[0], b[1]) != 1) {
        if (b[0] == min(b[0], b[1])) {
            b[1] = mx;
            ans.pb({0, 1, b[0], mx});
        }
        else {
            b[0] = mx;
            ans.pb({0, 1, mx, b[1]});
        }
    }
    for (int i = 2; i < n; ++i) {
        if (__gcd(b[i], b[i-1]) != 1) {
            if (b[i] == min(b[i-1], b[i])) {
                if (b[i-2] == mx) {
                    b[i-1] = mx2;
                    ans.pb({i-1, i, mx2, b[i]});
                }
                else {
                    b[i-1] = mx;
                    ans.pb({i-1, i, mx, b[i]});
                }
                // cout << "i\t" << i << "\n";
            }
            else {
                b[i] = mx;
                ans.pb({i, i-1, mx, b[i-1]});
                // cout << "i-1\n" << i << "\n";
            }
        }
    }
    cout << ans.size() << "\n";
    vector<ll> c;
    c = a;
    // print(b);
    if (ans.size() != 0) {
        EACH(it, ans) {
            ll a1, a2, a3, a4;
            tie(a1, a2, a3, a4) = it;
            a1++;
            a2++;
            cout << a1 << " " << a2 << " " << a3 << " " << a4<<"\n";
        }
    }
}