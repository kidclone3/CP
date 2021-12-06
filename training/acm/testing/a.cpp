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

int check[4];
vi test;
int n;
vi a;
vl res;
void out() {
    vi aa, bb, cc;
    FOR(i, 3*n) {
        if (test[i] == 1) aa.push_back(a[i]);
        if (test[i] == 2) bb.pb(a[i]);
        if (test[i] == 3) cc.pb(a[i]);
    }
    ll ans = 0;
    FOR(n) {
        ans += (aa[i] - bb[i]) * cc[i];
    }
    res.pb(ans);
}
void backtrack(int i) {
    if (i == 3*n) {
        out();
        return;
    }
    for(int j = 1; j<= 3; ++j) {
        if (check[j] + 1 <= n) {
            test[i] = j;
            check[j]++;
            backtrack(i+1);
            check[j]--;
        }
    }
}

void solve(){
    a.clear();
    a.resize(3*n);
    memset(check, 0, sizeof check);
    test.resize(3*n, 0);
    res.clear();
    FOR(3*n) cin >> a[i];
    vi tmp=
    backtrack(0);
    ll mx = LLONG_MIN;
    EACH(it, res) mx = max(mx, it);
    cout << mx <<'\n';
}

int main()
{
    IOS;
    int t; cin >> t; cin >> n;
    while(t--) solve();
}