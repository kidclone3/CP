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
int solve() {
    int n, m; cin >> n >> m;
    vvl a(n, vl(m));
    FOR(n) 
        FOR(j, m)
            cin >> a[i][j];
    ll ans = 0LL;
    int nn = n, mm = m;
    if (n&1) nn += 1;
    if (m&1) mm += 1;
    FOR(i, nn/2)
        FOR(j, mm/2) {
            vl tmp(4);
            tmp[0] = a[i][j];
            tmp[1] = a[n-i-1][j];
            tmp[2] = a[i][m-j-1];
            tmp[3] = a[n-i-1][m-j-1];
            sort(all(tmp));
            ll mean = (tmp[1] + tmp[2])/2;
            ll add = abs(a[i][j] - mean) + abs(a[n-i-1][j] - mean) + abs(a[i][m-j-1]-mean) + abs(a[n-i-1][m-j-1]-mean);
            if (i == n-i-1 || j == m-j-1) {
                ans += add/2;
            } else ans += add;
        }
    cout << ans << '\n';
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
    while(t--)
    solve();
    return 0; 
}

