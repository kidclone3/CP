#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
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
const ll mod = 998244353;
const int N = 2e5+5;

// array to store factorial of first N numbers
ll fact[N + 1];
// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 

ll nPr(ll n, ll r) {
    ll ans = (fact[n] * factorialNumInverse[n-r]) % mod;
    return ans;
}

void solve(){
    ll n; cin >> n;
    vl a(n);
    FOR(n) cin >> a[i];
    sort(all(a)); reverse(all(a));
    // Dem xem bao nhieu so lon nhat.
    ll mx = 1;
    FOR(i, 1, n) if (a[i] == a[0]) mx++; else break;
    if (mx == n) {
        cout << nPr(n, n) << "\n";
        return;
    }
    ll mx2 = 0;
    FOR(i, 1, n) if (a[i] == a[0] - 1) mx2++;
    if (mx2 == 0) {
        cout << "0\n"; return;
    }
    ll ans = (nPr(n-1, mx) * fact[n-mx]) % mod;
    // cout << ans << "\n";
    ll mx3 = n - mx - mx2;
    FOR(i, 1, (int) mx3+1) {
        // ll tmp = 0;
        ll tmp = (nPr(mx3, i)*mx*fact[n-i-1]);
        ans = (ans - tmp + mod*mod) % mod;
    }
    cout << ans << "\n";
}   

int main()
{
    IOS;
    // int mod = 0;
    InverseofNumber(mod);
    InverseofFactorial(mod);
    factorial(mod);

    int t; cin >> t;
    while(t--) solve();
}