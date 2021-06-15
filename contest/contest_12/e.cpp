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
void solve() {
    int n;
    cin >> n;
    vector<int> a(3), b(3), a1, a2;
    FOR(3) cin >> a[i];
    FOR(3) cin >> b[i];
    int mn1, mn2, mx;
    mn1 = mn2 = mx = 0;
    mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    a1 = a2 = a;
    // Xu ly tung cai 1.
    // dau tien la a[0].
    FOR(j, 2) {
        for (int i = 0; i < 3 ; ++i) {
            int tmp;
            if (b[(i-1 + 3) % 3] >= b[i]) {
                tmp = (i - 1 + 3) % 3;
            }
            else {
                tmp = i;
            }
            if (b[tmp] >= a1[i]) {
                b[tmp] -= a1[i];
                a1[i] = 0;
            }
            else {
                a1[i] -= b[tmp];
                b[tmp] = 0;
            }
        }
    }
    FOR(j, 2) {
        for (int i = 0; i < 3 ; ++i) {
            int tmp;
            if (b[(i-1 + 3) % 3] > b[i]) {
                tmp = (i - 1 + 3) % 3;
            }
            else {
                tmp = i;
            }
            if (b[tmp] >= a2[i]) {
                b[tmp] -= a2[i];
                a2[i] = 0;
            }
            else {
                a2[i] -= b[tmp];
                b[tmp] = 0;
            }
        }
    }
    FOR(3) {
        // cout << a[i] << " ";
        mn1 += a1[i];
        mn2 += a2[i];
    }
    // FOR(3) {
    //     cout << b[i] << " ";
    // }
    cout << min(mn1, mn2) << " " << mx;
}
