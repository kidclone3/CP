#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    // snt();
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        for (ll i = 2; i*i <= n; ++i) {
            while(n % i == 0) {
                cout << i << " ";
                n/=i;
            }
        }
        if (n != 1) cout << n;
        cout << "\n";
    }
}