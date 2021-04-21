#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
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
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
int a[100+5], dp[100+5];
void solve() {
    int n;
    cin >> n;
    int c_1 = 0, c_0 = 0;
    int mx = INT_MIN;
    FOR(i, n) {
        cin >> a[i];
        (a[i]) ? (c_1++) : (c_0++);
        if (i==0 && a[i] == 0) {
            dp[i] = 1;
            mx = max(mx, dp[i]);
            continue;
        }
        if (a[i] == 0) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            dp[i] = 0;
        }
        mx = max(mx, dp[i]);
    }  
    if (n == 1 && a[0] == 1) {
        cout << 0;
        return;
    } 
    cout << max(mx + c_1, c_0);
}