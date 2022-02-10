// https://codeforces.com/contest/1195/problem/D1
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

const ll MOD =  998244353;
ll f(ll x) {
    ll sum = 0LL;
    ll i = 1LL;
    while (x) {
        ll dig = x % 10LL;
        (sum += dig * i % MOD) %= MOD;
        i*=10LL;
        (sum += dig * i % MOD) %= MOD;
        i*=10LL;
        x /= 10LL;
    }
    return (sum% MOD + MOD) % MOD;
}

void solve(){
    ll n; cin >> n;
    vl a(n);
    ll ans = 0;
    FOR(n) {
        cin >> a[i];
        cout << "\t" << f(a[i]) << "\n";
        ans = (ans + f(a[i])) % MOD;
        (ans += MOD) %= MOD;
        cout << ans << '\n';
    }
    cout << (n * ans % MOD + MOD) % MOD;
}

int main()
{
    IOS;
    solve();
}