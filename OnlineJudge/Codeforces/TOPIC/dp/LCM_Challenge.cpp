// https://codeforces.com/problemset/problem/235/A
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
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
void solve();
const int N = 1e6+5;
bool f[N];
vector<ll> prime;
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (f[i]) continue;
        for (int j = 2*i; j <= n; j+=i) {
            f[j] = true;
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (!f[i]) {
            prime.push_back(i);
        }
    }
}
int main()
{
    IOS;
    solve();
}
void solve() { 
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n == 2) {
        cout << 2;
        return;
    }
    if (n == 3) {
        cout << 6;
        return;
    }
    if (n == 4) {
        cout << 12;
        return;
    }
    sieve(n);
    ll ans = 0LL;
    // print(prime);
    auto tmp = --lower_bound(all(prime), n);
    ll left = *(--tmp);
    // cout << left << "\n";
    for (ll i = n; i >= left; --i) {
        for (ll j = i; j >= left; --j) {
            for (ll z = j; z >= left; --z) {
                ll lcm = i * j / __gcd(i, j);
                lcm = lcm * z / __gcd(lcm, z);
                ans = max(ans, lcm);
            }
        }
    }
    cout << ans;
}
