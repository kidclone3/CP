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

const ll mod = 1e9 + 7;

vector<vl> mul(vector<vl> &a, vector<vl> &b) {
    vector<vl> ans(6, vl(6, 0LL));
    FOR(i, 6) FOR(j, 6) FOR(k, 6) {
        (ans[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
    }
    // print(ans[0]);
    return ans;
}

void solve(){
    ll a[7] = {0, 1, 2, 4, 8, 16, 32};
    ll n; cin >> n;
    if (n <= 6) cout << a[n];
    else {
        vector<vl> p = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
        vector<vl> ans = {{1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}};
        n -= 6;
        // print(p[0]);
        while(n) {
            // print(p[0]);
            if (n&1) ans = mul(ans, p);
            p = mul(p, p);
            
            n >>= 1;
        }
        ll res = 0;
        // print(ans[0]);
        FOR(i, 6) (res += a[6-i] * ans[0][i] % mod) %= mod;
        cout << res;
    }
}

int main()
{
    IOS;
    solve();
}