#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
map<ll, ll> F;

ll f(ll n) {
    if (F.count(n)) return F[n];
    ll k = n/2;
    if (n%2 == 0)
        return F[n] = (f(k)*f(k) % mod + f(k-1) * f(k-1) % mod) % mod;
    else
        return F[n] = (f(k)*f(k+1) % mod +f(k-1)*f(k) % mod) % mod;
}

int main() {
    F[0] = F[1] = 1;
    ll n; cin >> n;
    if (n == 0) cout << 0;
    else {
        cout << f(n-1);
    }
}