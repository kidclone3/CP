#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main() {
    int n; cin >> n;
    vector<long long> a(n+5);
    a[0] = 1;
    a[1] = 3;
    for(int i = 2; i <= n; ++i) a[i] = 2*(a[i-1] + a[i-2]) % MOD;
    cout << a[n];
}