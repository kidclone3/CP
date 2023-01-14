#include <bits/stdc++.h>
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

vi addr;
ll cost(int p) {
    ll ans = 0;
    FOR(i, 0, addr.size(), p) {
        int median = addr[(2*i + p - 1)/2];
        FOR(j, i, i+p) {
            ans += (ll) abs(addr[j]-median);
        }
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    
    vi a(n); FOR(n) {
        cin >> a[i];
        if (a[i]) addr.push_back(i);
    }
    int mx = addr.size();
    if (mx <= 1) {
        cout << -1;
        return;
    }
    ll ans = LLONG_MAX;
    int p = 2, tmp = mx;
    while(p*p <= tmp) {
        if (tmp % p == 0) {
            ans = min(ans, cost(p));
            while(tmp % p == 0) tmp /= p;
        }
        ++p;
    }
    if (tmp > 1) ans = min(ans, cost(tmp));
    cout << ans;
}
// My old code was not AC because I wasn't handle except good enough. I was just naive.
int main()
{
    IOS;
    solve();
}