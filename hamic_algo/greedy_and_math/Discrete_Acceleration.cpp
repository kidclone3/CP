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
bool equal(double a, double b) {
    return abs(a-b) <= 1e-6;
}
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
}
void solve() {
    int n, l;
    cin >> n >> l;
    vector<double> a(n+2);
    a[0] = -1e18;
    FOR(i, 1, n+1) cin >> a[i];
    a[n+1] = 1e18;
    double left = 0.0, right = 1.0*l;
    int i = 1, j = n;
    double v1, v2;
    v1 = v2 = 1.0;
    double ans = 0.0;
    while(!equal(left, right)) {
        double time = min((a[i] - left) / v1, min((right - a[j])/v2, (right - left)/(v1+v2)));
        left += time * v1;
        right -= time * v2;
        if (i+1 < n+2 && equal(left, 1.0*a[i])) {
            v1+=1.0;
            i++;
        }
        if (j-1 >= 0 && equal(right, 1.0*a[j])) {
            v2+=1.0;
            j--;
        }
        ans += time;
    }   
    // cout << ans << "\n";
    printf("%.10f\n", ans);
}
