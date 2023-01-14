#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int)(b) : i>(int)(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
        d4y[] = {0, -1, 0, 1},
        d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cerr << it << " ";
    }
    cerr << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cerr << "(" << it.first << ", " << it.second <<") ";
    }
    cerr << "\n";
};

ll countPath(ll x, ll n) {
    if (x > n) return 0;
    queue<pair<ll, ll>> q;
    if (x & 1) q.push({x, x});
    else q.push({x, x+1});
    ll ans = 0LL;
    while(!q.empty()) {
        pair<ll, ll> top = q.front();
        q.pop();
        ans += min(n, top.se) - top.fi + 1;
        if (top.fi * 2 <= n) q.push({2*top.fi, 2*top.se + 1});
    }
    return ans;
}

int solve() {
    ll n, k;
    cin >> n >> k;
    ll left = 1, right = n/2;
    ll ans = 1;
    while (left <= right) {
        ll mid = (left+right)/2;
        if (mid == 0) break;
        if (countPath(mid<<1, n) >= k) {
            ans = max(ans, mid<<1);
            // cerr << ans << '\n';
            left = mid + 1;
        } else right = mid - 1;
    }
    left = 0, right = n/2;
    while (left <= right) {
        ll mid = (left+right)/2;
        if (countPath(mid<<1|1, n) >= k) {
            ans = max(ans, mid<<1|1);
            left = mid + 1;
        } else right = mid - 1;
    }
    cout << ans;
    return 0;
}
int main() {
    IOS;
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#else
	// online submission
#endif
    solve();
    return 0; 
}

