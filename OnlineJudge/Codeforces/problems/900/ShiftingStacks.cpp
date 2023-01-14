#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve() {
    int n;
    cin >> n;
    ll a[n+1];
    int dp[n+1];
    F_OR(i, 0, n+1, 1) {
        dp[i] = 0;
    }
    a[0] = -1;
    F_OR(i, 1, n+1, 1) {
        cin >> a[i];
    }
    if (a[1] >= 1) {
        a[2] += a[1];
        a[1] = 0;
    }
    F_OR(i, 2, n, 1) {
        if (a[i] >= a[i-1] + 1) {
            a[i+1] += a[i] - (a[i-1] +1);
            a[i] = a[i-1] + 1; 
        }
        else {
            cout<<"NO\n";
            return;
        }
    }
    if (a[n-1] >= a[n]) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;
    

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
