#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll powM(ll x, ll n) {
    ll ans = 1LL;
    for(; n; x = x*x, n >>=1) {
        if (n & 1) ans *= x;
    }
    return ans;
}
// Driver Code
int main()
{
    // int N = 3;
    int t; cin >> t;
    while(t--) {
        // int N; cin >> N;
        string s; cin >> s;
        int N = s.size();
    
        // Formula for number of trails for
        // N consecutive heads
        // cout << (ll) pow(2, N + 1) - 2;
        cout << powM(2, N+1)-2 << "\n";
    }
    return 0;
}