#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e6+5;
const ll MOD = 1e9+7;
int main() {
    int n; cin >> n;
    ll dp[N];
    dp[1] = 1;
    dp[2] = 1<<1;
    dp[3] = 1<<2;
    dp[4] = 1<<3;
    dp[5] = 1<<4;
    dp[6] = 1<<5;
    if (n <= 6) return cout << dp[n], 0;
    for(int i = 7; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
        dp[i] %= MOD;
    }
    cout << dp[n];
    return 0;
}
