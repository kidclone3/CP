#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
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
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
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

const int N = 105;
vi prime;
vi lpf(N, 2);

void sieve() {
    prime.assign(1, 2);
    lpf[1] = -2;
    for(int i = 3; i <N; i += 2) {
        if (lpf[i] == 2) prime.pb(lpf[i] = i);
        for(int j = 0; j < (int) prime.size() && prime[j] <= lpf[i] && i * prime[j] < N; ++j) {
            lpf[i*prime[j]] = prime[j];
        }
    }
}

int solve() {
    int n; cin >> n;
    vl a(N, 0LL);
    FOR(n) {
        ll l, r; cin >> l >> r;
        while(l > 1) {
            ll p = lpf[l], cnt = 0LL;
            do l /= p, cnt++;
            while(p == lpf[l]);
            a[p] += cnt * r;
        }
    }
    auto check = [&](ll x) -> bool {
        FOR(i, N) if (a[i]) {
            ll tmp = x, cnt = 0;
            while(tmp) {
                cnt += tmp / i;
                tmp /= i;
            }
            if (cnt < a[i]) return false;
        }
        return true;
    };
    // FOR(10) cout << i << " " << a[i] << "\n";
    ll l = 1;
    ll r = 1e18;
    // ll r = 100;
    ll mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    // while(!check(l))l++;
    cout << l << "\n";
    // FOR(i, l, l+10) if (check(i)) return cout << l << "\n", 0;
    return 0; 
}

int main()
{
    IOS;
    sieve();
    int t; cin >> t;
    while(t--)
    solve();
}