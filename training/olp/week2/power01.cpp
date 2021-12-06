#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

vl phi;
const ll N = 1e7+5;

ll addMod(ll a, ll b, ll m) {return ((a+b) % m + m) % m;}

ll mulMod(ll a, ll b, ll m) {
    ll res = 0;
    for(a %= m, b %= m; b > 0; a = addMod(a, a, m), b >>= 1) 
        if (b & 1) res = addMod(res, a, m);
    return res;
}

ll powMod(ll x, ll n, ll m) {
    ll res = 1;
    for (x %= m; n > 0; x = mulMod(x, x, m), n >>= 1)
        if (n & 1) res = mulMod(res, x, m);
    return res;
}

ll ans = 0;

ll g(ll p, ll n, ll m) {
    if (n == 0) return 1;
    if (n == 1) return addMod(1, p, m);
    if (n & 1) return addMod(1, mulMod(p, g(p, n-1, m), m), m);
    return addMod(1, mulMod(addMod(1, powMod(p, n >> 1, m), m), addMod(g(p, n >> 1, m), - 1, m), m), m);
}

void solve(){
    ll x, n, m;
    cin >>x >> n >> m;
    cout << g(x, n, m);
}

int main()
{
    IOS;
    // phi_1_to_n();
    solve();
}