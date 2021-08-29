#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m = 1e9+7;
ll maxProduct(vector<ll> a) {
    ll mx = -1e9;
    ll tich1 = 1;
    ll tich2 = 1;
    int n = a.size();
    vector<ll> v1(n, 1), v2(n, 1);
    v1[0] = a[0];
    for (int i = 1; i < n; ++i) {
        v1[i] = v1[i-1] * a[i] % m;
    }
    v2[n-1] = a[n-1];
    for (int i = n-2; i > -1; --i) {
        v2[i] = v2[i+1] * a[i] % m;
    }
    for(int i = 1; i < n; ++i) {
        mx = max(mx, (v1[i-1] + v2[i]) % m);
    } 
    return mx;
}

int main(){
    vector<ll> a = {-1,3,4,-2}; 
    cout << maxProduct(a);
    // cout << power(-1, 4);
}