#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll unsigned long long
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

ll div_mod(ll x) {
    x %= mod;
    return x < 0 ? x + mod : x;
}

ll pow_mod(ll a, ll b) {
    ll ans = 1;
    ll p = a;
    while(b) {
        if (b & 1){
            ans *= div_mod(p);
            ans = div_mod(ans);
        }
        p = div_mod(p * p);
        b >>= 1;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    ll top = 1;
    FOR(i, 1, n+1) {
        top = div_mod(top * (ll) i);
    }
    ll down = 1;
    // a^-1 % mod = a^(m-2) % mod
    FOR(i, 1, r+1)  {
        down *= pow_mod(i, mod-2);
        down = div_mod(down);
    }
    FOR(i, 1, n-r+1) {
        down *= pow_mod(i, mod-2);
        down = div_mod(down);
    }
    return div_mod(top * down);
}

void solve(){
    int n; cin >> n;
    vl L(n), R(n);
    FOR(n) cin >> L[i];
    FOR(n) cin >> R[i];
    sort(all(L));
    sort(all(R)); reverse(all(R));
    ll ans = 0;
    FOR(n) ans += abs(L[i] - R[i]);
    cout << div_mod(ans * nCr(2*n, n));
}

int main()
{
    IOS;
    solve();
}