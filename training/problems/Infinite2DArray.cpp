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
void inputIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // inputIO;
    solve();
}
ll mod = 1e9+7;
void solve() {
    int x, y;
    cin >> x >> y;
    // tao 1 mang fibo.
    vector<ll> f(max(x, y) + 1), dp(max(x, y) + 1);
    f[0] = 0; f[1] = 1;
    dp[0] = 0; dp[1] = 1;
    F0R(i, 2, max(x, y)+1) {
        f[i] = (f[i-1] % mod + f[i-2] % mod) % mod;
        dp[i] = (dp[i-1] % mod + f[i] % mod) % mod;
    }
    print(f);
    print(dp);
    ll ans = (dp[x] % mod + dp[y] % mod) % mod;
    cout << ans;
}