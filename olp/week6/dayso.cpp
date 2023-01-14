#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
// #pragma GCC optimize("O3,unroll-loops")

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
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
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

class matrix {
    public:
    ll a[3][3];
    matrix() {
        // memset(a, 0, sizeof a);
        setZero();
        a[0][0] = a[1][1] = a[2][2] = 1;
    }
    void setZero() {
        memset(a, 0, sizeof a);
    }
    void setMatrix() {
        // memset(a, 0, sizeof a);
        setZero();
        a[0][0] = 2; a[0][1] =-1; a[0][2] = 2;
        a[1][0] = a[2][1] = 1;
    }
    void print() {
        FOR(i, 3) FOR(j, 3) cout << a[i][j] << " \n"[j==2];
    }
};

matrix operator * (const matrix &a, const matrix &b) {
    matrix ans;
    // FOR(i, 3) FOR(j, 3) ans.a[i][j] = 0;
    ans.setZero();
    FOR(i, 3) FOR(j, 3) FOR(k, 3) {
        ans.a[i][j] += a.a[i][k] * b.a[k][j];
    }
    return ans;
}

matrix powMod(matrix a, int n) {
    matrix ans;
    if (n == 0) return ans;
    if (n == 1) return a;
    n -= 2;
    ans.print();
    for(; n; a = a*a, n >>= 1) {
        if (n&1) {
            ans = ans * a;
            ans.print();
            cout << "\n";
        }
    }
    return ans;
}

ll getVal(const matrix &a) {
    return a.a[0][0]*3 + a.a[0][1]*1 + a.a[0][2];
}

int solve() {
    matrix a;
    a.setMatrix();
    // cout << a.a[0][0] << " " << a.a[0][1] << " " << a.a[0][2] << "\n";
    // a.print();
    int n; cin >> n;
    // ll an = getVal(powMod(a, n));
    // ll an1 = getVal(powMod(a, n+1));
    // ll ak = an * an1;
    // // cout << an << " " << an1 << "\n";
    // cout << ak << "\n";
    matrix tmp = powMod(a, 5);
    tmp.print();
    cout << getVal(tmp);
    // int left = 1, right = 1e9;
    // int k = -1;
    // while(left <= right) {
    //     int mid = (left + right) / 2;
    //     ll tmp = getVal(powMod(a, mid-2));
    //     if (ak == tmp) {k = mid; break;}
    //     else if (ak > tmp) left = mid + 1;
    //     else right = mid - 1;
    // }
    // cout << k;
    return 0; 
}

int main()
{
    IOS;
    solve();
}