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

const ll mod = 1e9+7;

struct matrix{
    // matrix look like: x1 x2
    //                   y1 y2
    ll x1, x2, y1, y2;
    matrix() {x1 = 0, x2 = 0, y1 = 0, y2 = 0; };
    matrix(ll a, ll b, ll c, ll d) {
        x1 = a, x2 = b, y1 = c, y2 = d;
    }
};
matrix operator *(const matrix &a, const matrix &b) {
    matrix tmp;
    tmp.x1 = (a.x1*b.x1 % mod + a.x2 * b.y1 % mod) % mod;
    tmp.x2 = (a.x1*b.x2 % mod + a.x2 * b.y2 % mod) % mod;
    tmp.y1 = (a.y1*b.x1 % mod + a.y2 * b.y1 % mod) % mod;
    tmp.y2 = (a.y1*b.x2 % mod + a.y2 * b.y2 % mod) % mod;
    return tmp;
}

void solve(){
    ll n; cin >> n;
    matrix C(1, 1, 1, 0), ans(1, 0, 0, 1);
    if (n == 0) {cout << 0; return;}
    else if (n == 1 || n == 2) {
        cout << 1; return;
    }
    while(n) {
        if (n&1) {
            ans = ans * C;
        }
        C = C * C;
        n >>= 1; 
    }
    cout << ans.x2;
}

int main()
{
    IOS;
    solve();
}