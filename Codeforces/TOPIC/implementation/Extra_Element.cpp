// https://codeforces.com/problemset/problem/1185/D
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
        cout << it.first << ", " << it.second <<";  ";
    }
    cout << "\n";
};
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    FOR(i, n) {
        a[i].second = i;
        cin >> a[i].first;
    }
    sort(all(a));
    // tao 1 vector chua khoang cach giua cac diem.
    vector<ll> d(n-1);
    FOR(i, 0, n-1) {
        d[i] = a[i+1].first - a[i].first;
    }
    bool f = true;
    for (int i = 2; i < n-1; ++i) {
        f &= d[i] == d[1];
    }
    if (f) {
        cout << a[0].second + 1;
        return;
    }
    f = true;
    for (int i = 2; i < n-1; ++i) {
        f &= d[i] == (a[2].first - a[0].first);
    }
    if (f) {
        cout << a[1].second + 1;
        return;
    }
    // Chi? = nhung dong nay => ktra dc th a[0], a[1] co' phai la so' can` tim.
    int ans;
    f = false;
    FOR(i, 1, n-1) {
        if (d[i] == d[0]) continue;
        if (f) {
            cout << "-1";
            return;
            // Luc nay thi da co 2 so voi khoang cach khac d[0].
        }
        else {
            if (i == n-2) {
                cout << a[n-1].second + 1;
                return;
                // Neu da duyet den phan tu cuoi cung, va no' khac
                // => a[n-1] la so can tim.
            }
            else {
                if (a[i+2].first - a[i].first == d[0]) {
                    ans = a[i+1].second;
                    f = true;
                    i++;
                    // Da tim dc phan tu can` tim` dau tien.
                    // Neu co them 1 phan tu nhu nay nua =>
                    // line 76 => tach
                }
                else {
                    // Nuoc nay thi da loan vcl roi, ko cuu chua dc.
                    cout << "-1";
                    return;
                }
            }
        }
    }
    if (f) {
            cout << ans + 1;
            // Neu tim` thay 1 lan thi in ra.
        }
        else {
            cout << a[n-1].second + 1;
            // Den day thi day la csc cmnr => xoa phan tu dau hay cuoi
            // Cung duoc.
        }
}
