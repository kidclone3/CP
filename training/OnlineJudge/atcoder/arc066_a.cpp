#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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
const ll mod = 1LL*(1e9+7);
ll pow_mod(ll a, ll n) {
    ll ans = 1LL;
    for (ll i = n; i; i >>= 1) {
        if (i&1) {
            (ans *= a) %= mod;
        }
        a = a * a % mod;
    }
    return ans;
}
void solve(){
    int n; cin >> n;
    map<int, int> mp;
    int a[n];
    FOR(n) {
        cin >> a[i];
    }
    FOR(n) {
        mp[a[i]]++;
        if (mp[a[i]] > 2) {
            cout << 0;
            return;
        }
    }
    EACH(it, mp) {
        if (it.first != 0 && it.second == 1) {
            cout << 0;
            return;
        }
    }
    int sz = mp.size();
    if (n&1) {
        sz--;
        if (mp[0] > 1 || mp[1] != 0) {
            cout << 0;
            return;
        }
    }
    else {
        if (mp[0] != 0) {
            cout << 0;
            return;
        }
    }
    // cout << sz;
    cout << pow_mod(2, sz) << "\n";
    // cout << (1ll<<sz % mod);
}

int main()
{
    IOS;
    solve();
}