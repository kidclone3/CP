#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

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

void solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> pos(n);
    FOR(n) cin >> pos[i].first >> pos[i].second;
    vector<double> dis(n, 0.0);
    auto distance = [&] (pair<ll, ll> &x1, pair<ll, ll> &x2) -> double {
        return abs(x1.fi-x2.fi) + abs(x1.se - x2.se);
    };
    FOR(i, n) {
        FOR(j, n) {
            dis[i] += distance(pos[i], pos[j]);
        }
    }
    pair<ll, ll> ans;
    double mn = 1e18;
    FOR(n) {
        if(dis[i] < mn) {
            mn = dis[i];
            ans = pos[i];
        } else if(abs(dis[i] - mn) < 1e-6) {
            if (pos[i].fi < ans.fi) ans = pos[i];
            else if(pos[i].se < ans.se) ans = pos[i];
        }
    }
    // print(dis);
    cout << ans.fi << " " << ans.se;
}

int main()
{
    IOS;
    solve();
}