#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
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
const int N = 1e3+5;
int f[N][N];
string x, y;
int memoization_approach(int n, int m) {
    if (f[n][m]) return f[n][m];
    if (n == 0 && m == 0) {
        return 0;
    }
    if (n == 0) {
        // f[n][m] = f[n][m-1] + 1;
        f[n][m] = m;
        return f[n][m];
    }
    if (m == 0) {
        // f[n][m] = f[n-1][m] + 1;
        f[n][m] = n;
        return f[n][m];   
    }
    f[n][m] =   min(memoization_approach(n-1, m) + 1, 
                min(memoization_approach(n, m-1) + 1, 
                memoization_approach(n-1, m-1) + (x[n] != y[m])));
    return f[n][m];
}
int tabulation_approach(int n, int m) {
    for (int i = 0 ; i <= n; ++i) {
        f[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        f[0][j] = j;
    }
    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = min(f[i-1][j] + 1, min(f[i][j-1] + 1, f[i-1][j-1] + (x[i] != y[j])));
        }
    }
    return f[n][m];
}
void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    cin >> x >> y;
    x = '!' + x;
    y = '!' + y;
    // cout << x << " " << y << "\n";
    // cout << memoization_approach((int) x.size() - 1, (int) y.size() - 1);
    cout << tabulation_approach((int) x.size() - 1, (int) y.size() - 1);
    cout << '\n';
    for (int j = 0; j < (int) y.size(); j++) {
        for(int i = 0; i < (int) x.size(); ++i)
        {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }

}
