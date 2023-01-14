#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n; cin >> n;
    ll a[n+1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll dp[n+5];
    dp[0] = 1;
    for(int i =1; i <= n; ++i) {
        if (dp[i-1] < a[i]) return cout << dp[i-1], 0;
        dp[i] = dp[i-1] + a[i];
    }
    cout << dp[n];
}