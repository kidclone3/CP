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
int getBest(vi &a, int curr) {
    int mn = INT_MAX;
    int idx = -1;
    FOR(i, a.size()) {
        if (abs(a[i] - curr) < mn) {
            mn = abs(a[i]-curr);
            idx = i;
        }
    }
    return idx;
}
int solve() {
    int n; cin >> n;
    vi a(n), b(n);
    FOR(n) cin >> a[i];
    FOR(n) cin >> b[i]; 
    vi tmp1 = {0, getBest(b, a[0]), n-1};
    vi tmp2 = {0, getBest(b, a[n-1]), n-1};
    

    ll res = LLONG_MAX;
    for(auto it1: tmp1) {
        for(auto it2: tmp2) {
            ll sum = 1LL*(abs(a[0] - b[it1])) + 1LL*(abs(a[n-1] - b[it2]));
            if (it1 > 0 && it2 > 0) {
                sum += 1LL*abs(b[0] - a[getBest(a, b[0])]);
            }
            if (it1 < n-1 && it2 < n-1) {
                sum += 1LL*abs(b[n-1] - a[getBest(a, b[n-1])]);
            }
            res = min(res, sum);
        }
    }
    cout << res << '\n';

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
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}

