#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
const ll MOD = 1e9+7;
int main() {
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    ll dp[N][N];
    memset(dp, 0, sizeof dp);
    dp[1][1] = (a[0][0] == '.');
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if (a[i-1][j-1] == '.') {
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][n];
}
