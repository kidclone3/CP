#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int N = 1e6+5;

int main() {
    int n, X; cin >> n >> X;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll dp[N];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = a[i]; j <= X; ++j) {
            if (j == a[i]) {
                dp[j]++;
                dp[j] %= MOD;
            } else {
                dp[j] += dp[j-a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[X];
}
