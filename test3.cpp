#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int P = 1e5+3;

ll factorial[P+5];
ll invFactorial[P+5];

ll powMod(ll x, ll p) {
    ll ans = 1LL;
    for (; p > 0; x = x*x % P, p >>= 1) {
        if (p&1) ans = ans*x;
    }
    return ans;
}

void factorialMod() {
    factorial[1] = invFactorial[1] = 1;
    for(int i = 2; i <= P; ++i) {
        factorial[i] = factorial[i-1]*i % P;
        invFactorial[i] = powMod(factorial[i], P-2);
    }
}

ll nCr(ll n, ll r) {
    return factorial[n] * (invFactorial[r] * invFactorial[n-r] % P) % P;
}

ll nCrLucas(ll n, ll r) {
    if (r == 0) return 1LL;
    ll ni = n%P, ri = r%P;

    return nCrLucas(n/P, r/P) * nCr(ni, ri) % P;

}

int solve() {
    ll n, m, k;
    cin >> m >> n >> k;
    if (log(m) < log(n) + log(k))
        return cout << 0, 0;
    ll remainder = m - n*k +k - 1;
    // cerr << remainder << '\n';
    cout << nCrLucas(n, remainder) << '\n';
    // cout << 
    return 0;
}

int main() {
    // PreCalculate
    factorialMod();
    int t; cin >> t;
    while(t--) solve();
}
