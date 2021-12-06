#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define sz (int)(x).size()
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

const int N = 1e6+5;
vi primes;
vi lpf(N+1, 2);

void sieve() {
    primes.assign(1,2);
    lpf[1] = -2;
    for(int i = 3; i <= N; i+=2) {
        if (lpf[i] == 2) primes.push_back(lpf[i] = i);
        for (int j = 0; j < (int) primes.size() && primes[j] <= lpf[i] && primes[j]*i <= N; ++j)
            lpf[i*primes[j]] = primes[j];
    }
}

ll _pow(ll x, ll n) {
    ll res = 1LL;
    for(int i = n; i; x = x*x, i >>= 1) 
        if (i & 1) res *= x;
    return res;
}

ll G(int p, int n) {
    if (n == 0) return 1;
    if (n == 1) return 1 + p;
    if (n & 1) return 1 + p * G(p, n-1);
    else return 1LL*(1+_pow(p, n>>1))*(G(p, n>>1)-1) + 1;
    // (1+p^(n/2))*(G(p, n/2)-1)+1
}

bool check(int n) {
    ll sum = 1LL;
    int x = n;
    while(x > 1) {
        int p = lpf[x], f = 0;
        do x /= p, ++f;
        while (lpf[x] == p);
        sum *= G(p, f);
    }
    // cerr << sum << "\n";
    return sum > 2*n;
}

void solve(){
    int l, r;
    cin >> l >> r;
    int ans = 0;
    // cout << divisorSum(r) - divisorSum(l);
    FOR(i, l, r+1) {
        ans += check(i);
    }
    cout << ans;
}

int main()
{
    IOS;
    sieve();
    // cout << check(12);
    // cout << G(2, 5);
    solve();
}