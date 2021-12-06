#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int) (b) : i > (int) (b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 4*1e7+5;
vi primes;
vi lpf;

const ll MOD = 1200000090;

ll addMod(ll a, ll b) {return ((a+b) % MOD + MOD) % MOD;}

ll mulMod(ll a, ll b) {
    ll res = 0;
    for(a %= MOD, b %= MOD; b; a = addMod(a, a), b >>= 1) 
        if (b & 1) res = addMod(res, a);
    return res;
}

ll powMod(ll x, ll n) {
    ll res = 1;
    for(x %= MOD; n; x = x * x % MOD, n >>=1)
        if (n&1) res = res * x % MOD;
    return res;
}

ll S(ll p, ll n) {
    if (n == 0) return 1;
    if (n == 1) return addMod(1, p);
    if (n & 1) return addMod(1, p * S(p, n-1) % MOD);
    // return (1+p^n/2)(G(p, n/2)-1)+1
    return addMod((addMod(1, powMod(p, n>>1)) * addMod(S(p, n>>1), -1)) % MOD, 1);
}

void sieve() {
    primes.assign(1, 2);
    lpf.assign(N+1, 2);
    lpf[1] = -2;
    for(int i = 3; i <= N; i+=2) {
        if (lpf[i] == 2) primes.push_back(lpf[i] = i);
        for(int j = 0; j < (int) primes.size() && primes[j] <= lpf[i] && primes[j] * i <= N; ++j) {
            lpf[primes[j]*i] = primes[j];
        }
    }
}
// vb check(N+5, 1);
// void sieve() {
//     // check.flip();
//     check[0] = check[1] = false;
//     for(int i = 2; i*i <= N; ++i) {
//         if (check[i]) {
//             for(int j = 2*i; j <= N; j+=i) check[j] = false;
//         }
//     }
//     // int sz = count(all(check), 1);
//     // primes.resize(sz);
//     // int j = 0;
//     FOR(N) if (check[i]) primes.push_back(i);
    
// }

void solve(){
    ll n; cin >> n;
    ll ans = 1LL;
    // while(n > 1) {
    //     ll p = lpf[n], f = 0;
    //     do n /= p, ++f;
    //     while (lpf[n] == p);
    //     ans = mulMod(ans, S(p, f));
    // }
    // vl cnt(primes.size(), 0LL);
    FOR(i, primes.size()) {
        if (primes[i] > n) break;
        ll f = 0;
        ll tmp = primes[i];
        while(tmp <= n) {
            f += n/tmp;
            tmp *= primes[i];
        }
        ans = ans * S(primes[i], 3*f) % MOD;
    }
    cout << ans << "\n";
}

int main()
{
    IOS;
    sieve();
    // cout << S(2, 9);
    int t; cin >> t;
    while(t--) solve();
}