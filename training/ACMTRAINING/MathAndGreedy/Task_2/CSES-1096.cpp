#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it = (s.begin()); it != (s.end()); ++it)
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (int)(b) : i > (int)(b); i += (s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)       \
    F_ORC(__VA_ARGS__) \
    (__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n + 1, 1)
#define EACH(x, a) for (auto &x : a)

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
          d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cerr << it << " ";
    }
    cerr << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cerr << "(" << it.first << ", " << it.second << ") ";
    }
    cerr << "\n";
};

const ll MOD = 1e9 + 7;

struct matrix
{
    vvl val;
    matrix()
    {
        val.resize(6);
        FOR(i, 6)
        {
            val[i].assign(6, 0);
            val[i][i] = 1;
        }
    }
    void initBase()
    {
        val.resize(6);
        val[0].assign(6, 1);
        FOR(i, 1, 6)
        {
            val[i].assign(6, 0);
            val[i][i - 1] = 1;
        }
    }
    void initZero()
    {
        val.resize(6);
        FOR(i, 6)
        val[i].assign(6, 0LL);
    }
    friend matrix operator*(matrix &a, matrix &b)
    {
        matrix ans;
        ans.initZero();
        FOR(i, 6)
        FOR(j, 6)
        FOR(k, 6)
        {
            ans.val[i][j] += (a.val[i][k] * b.val[k][j]) % MOD;
            ans.val[i][j] %= MOD;
        }
        return ans;
    }
};

matrix powMod(ll n)
{
    matrix ans = matrix();
    matrix base;
    base.initBase();
    for (; n > 0LL; base = base * base, n >>= 1)
    {
        if (n & 1)
            ans = ans * base;
    }
    // FOR(i, 6) FOR(j, 6) cout << ans.val[i][j] << " \n"[j==5];
    return ans;
}

int solve()
{
    vi f = {1, 2, 4, 8, 16, 32};
    // f[i] = f[i-6] + f[i-5] + f[i-4] + f[i-3] + f[i-2] + f[i-1]
    // f[i-1] =                                             1
    // f[i-2] =                                    1
    // f[i-3] =                           1
    // f[i-4] =                  1
    // f[i-5] =         1
    ll n;
    cin >> n;
    if (n <= 6)
    {
        cout << f[n - 1];
    }
    else
    {
        n -= 6;
        matrix ans = powMod(n);
        // FOR(i, 6) FOR(j, 6) cout << ans.val[i][j] << " \n"[j==5];
        ll result = 0LL;
        FOR(6)
        {
            result += ans.val[0][i] * f[5 - i];
        }
        result %= MOD;
        cout << result;
    }
    return 0;
}
int main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#else
    // online submission
#endif
    solve();
    return 0;
}