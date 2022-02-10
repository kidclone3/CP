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

void solve(){
    int n; cin >> n;
    vl a(n), b(n), c(n);
    FOR(n) cin >> a[i];
    FOR(n) cin >> b[i];
    FOR(n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = 0LL;
    int upper = 0; // pointer for the upper part.
    FOR(mid, 0, n) {
        // Start mid from 0 to n.
        auto low = lower_bound(all(a), b[mid]) - a.begin();
        if (low == n || a[low] >= b[mid]) low--; 
        while(upper < n && c[upper] <= b[mid]) upper++;
        if (upper == n) break;
        ans += 1LL*(low+1)*(n-upper);
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
}