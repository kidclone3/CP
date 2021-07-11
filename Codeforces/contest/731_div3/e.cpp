#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
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
int n, k;
vi a, b;
vector<pii> aa;
void solve();
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
}
void solve() {
    cin >> n >> k;
    a.resize(k);
    b.resize(k);
    aa.resize(k);
    multiset<int> left, right;
    FOR(k) cin >> a[i]; 
    FOR(k) {
        cin >> b[i]; 
        aa[i] = {a[i], b[i]};
    }
    sort(all(aa));
    FOR(k) { 
        tie(a[i], b[i]) = aa[i];
        right.insert(b[i] + a[i]-1);
    }
    // print(a);
    // int _l = n-1;
    // int _r = 0;
    FOR(i, 1, n+1) {
        int tmp = INT_MAX;
        if (!left.empty()) tmp = min(tmp, *left.begin() - (n-i));
        if (!right.empty()) tmp = min(tmp, *right.begin() - (i-1));
        auto tmp1 = lower_bound(all(a), i);
        if (*tmp1 == i) {
            int index = tmp1 - a.begin();
            tmp = min(tmp, b[index]); 
            auto tmp2 = right.lower_bound(b[index] + i-1);
            right.erase(tmp2);
            left.insert(b[index] + n - i);
        }
        // _l--;
        // _r--;
        cout << tmp << " ";
    }
    cout << '\n';
}
