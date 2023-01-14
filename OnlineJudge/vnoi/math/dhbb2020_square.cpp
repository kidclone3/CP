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

const int maxN = 5e6+5;
vi prime(maxN, 0);

void sieve() {
    prime[0] = prime[1] = 1;
    for(int i = 3; i*i <=maxN; ++i) {
        if (prime[i] == 0) {
            for(int j = 2*i; j <= maxN; j+=i) prime[j] = i;
            prime[i] = i;
        }
    }
    for(int i = 1; i <= maxN; ++i) {
        if (prime[i] == 0) {
            prime[i] = i;
        }
        if (i % 2 == 0) prime[i] = 2;
    }
}
ll getMask(ll x) {
    ll res = 1;
    while(x > 1) {
        ll k = prime[x];
        ll cnt = 0;
        while (x % k == 0 && x > 1) {
            cnt++;
            x /= k;
        }
        if (cnt & 1) res *= k;
    }
    return res;
}
ll cnt[maxN];
void solve(){
    int n; cin >> n;
    sieve();
    FOR(i, 1, n+1) {
        ++cnt[getMask(i)];
    }
    ll ans = 0;
    FOR(n+1) {
        if (cnt[i] >= 3) {
            ll tmp = cnt[i];
            ll add = ((tmp - 2) * (tmp -1 ) * tmp) / 6;
            ans += add;
        }
    }
    cout << ans;
}  

int main()
{
    IOS;
    solve();
}