#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while(t--) {
        ll a, b, n, base;
        a = b = 0;
        base = 1;
        cin >> n;
        while(n) {
            a = a + base * (n%10);
            n/=10;
            b = b + base * (n%10);
            n/=10;
            base *= 10;
        }
        cout << (a+1) * (b+1) - 2 << "\n";
    }
}