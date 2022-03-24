#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> vt;

string isFibo(ll n) {
    return *lower_bound(vt.begin(), vt.end(), n) == n ? "IsFibo" : "IsNotFibo";
}

int main() {
    int t; cin >> t;
    vt.clear();
    vt.push_back(0);
    vt.push_back(1);
    vt.push_back(1);
    while(vt.back() < (ll) 1e10) {
        int n = vt.size();
        vt.push_back(vt[n-1] + vt[n-2]);
    }
    while(t--) {
        ll n; cin >> n; 
        cout << isFibo(n) << '\n';
    }
}
