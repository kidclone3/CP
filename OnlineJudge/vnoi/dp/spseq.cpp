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
const int maxn = 100000+5;
int a[maxn], lis[maxn], lds[maxn], x[maxn];
int n;

void _lis() {
    fill(x+1, x+n+1, INT_MAX);
    x[0] = INT_MIN;
    FOR(n) {
        int pos = lower_bound(x, x+n+1, a[i]) - x;
        lis[i] = pos;
        x[pos] = a[i];
        // cout << lis[i] << " "
    }
}

void _lds() {
    fill(x+1, x+n+1, INT_MAX);
    x[0] = INT_MIN;
    FOR(i, n-1, -1, -1) {
        int pos = lower_bound(x, x+n+1, a[i]) - x;
        lds[i] = pos;
        x[pos] = a[i];
    }
}


void solve(){
    cin >> n;
    lis[0] = 1;
    FOR(n) {
        cin >> a[i];
    }
// This is LIS, LDS problem
    _lis(); _lds();
    int ans = 0; 
    FOR(n) {
        ans = max(min(lis[i], lds[i]) * 2 - 1, ans);
    }
    cout << ans<<'\n';
}

int main()
{
    IOS;
    solve();
}