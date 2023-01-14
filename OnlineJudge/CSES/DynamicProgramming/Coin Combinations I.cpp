#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6+5;
const ll MOD = 1e9+7;
int main() {
    int n, X; cin >> n >> X;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll dp[N];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int x = 1; x <= X; ++x) {
        for(int i = 0; i < n; ++i) 
            if (x >= a[i]) {
                dp[x] += dp[x-a[i]];
                dp[x] %= MOD;
            }
        // for(int i = 0; i <= X; ++i) cerr << dp[i] << " ";
        // cerr <<'\n';
    }
    cout << dp[X];
}
