#include <bits/stdc++.h>
using namespace std;


#define ll long long
const ll MOD = 1e9+7;
long countArray(int n, int k, int x) {
    ll f[n+5][2];
    memset(f, 0LL, sizeof f);
    f[1][0] = 1LL;
    for(int i = 2; i <= n; ++i) {
        f[i][0] = f[i-1][1]*(k-1) % MOD;
        f[i][1] = (f[i-1][1]*(k-2) % MOD + f[i-1][0]) % MOD;
    }
    // for(int i = 0; i <= n; ++i) 
    //     for(int j = 0; j < 2; ++j) 
    //         cout << f[i][j] << " \n"[j == 1];
    return (x == 1? f[n][0] : f[n][1]);
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    cout << countArray(n, k, x);
}
