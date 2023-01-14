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

const ll MOD = 1e9+7;
vl T(15, 0);
typedef vector<vl> matrix;

matrix build() {
    matrix ans(15);
    ans[14] = T;
    FOR(i, 0, 14) {
        ans[i].assign(15, 0);
        ans[i][i+1] = 1;
    }
    return ans;
}
// matrix build() {
//     matrix ans(15);
//     ans[0] = T;
//     FOR(i, 1, 15) {
//         ans[i].assign(15, 0);
//         ans[i][i-1] = 1;
//     }
//     return ans;
// }

matrix mmul(matrix &a, matrix &b) {
    matrix ans(15);
    FOR(i, 15) {
        ans[i].assign(15,0);
        FOR(j, 15) {
            FOR(k, 15) {
                ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ans;
}

matrix mpowMod(matrix &x, ll n) {
    if (n==0) {
    matrix ans(15);
        FOR(i, 15) {
            ans[i].assign(15,0);
            ans[i][i] = 1;
        }    
        return ans;
    }
    else if (n & 1) {
        matrix tmp = mpowMod(x, n-1);
        return mmul(tmp, x);
    } else {
        matrix tmp = mpowMod(x, n >>1);
        return mmul(tmp, tmp);
    }
    // for(; n; x = mmul(x, x), n >>= 1)
    //     if (n & 1) ans = mmul(ans, x);
    // return ans;
    
}

int solve() {
    ll n; cin >> n;
    int k; cin >> k;
    FOR(k) {
        int x; cin >> x;
        T[15-x] = 1;
    }
    matrix C = build();
    // FOR(i, 15) FOR(j, 15) cout << C[i][j] << " \n"[j==14];
    vi f(16, 0);
    // f[15] = 1;
    FOR(i, 15) {
        FOR(j, i+1) {
            if (T[14-j]) {
                if (i == j) {
                    f[i]++;
                }
                else {
                    f[i] += f[i-j-1];
                }
            }
        }
    }
    // print(f);
    // cout << '\n';
    if (n <= 15) cout << f[n-1] * 2 % MOD;
    else {
        matrix ans = mpowMod(C, n-15);
        // FOR(i, 15) FOR(j, 15) cout << ans[i][j] << " \n"[j==14];
        unsigned ll res = 0LL;
        // FOR(15) res = (res + ans[14][i]*f[i]) % MOD;
        FOR(15) res = (res + ans[14][i]*f[i]) % MOD;
        cout << (res * 2) % MOD;
    }
    // print(f);
    return 0; 
}

int main()
{
    IOS;
    solve();
}