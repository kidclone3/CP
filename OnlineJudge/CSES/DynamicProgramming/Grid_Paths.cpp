// https://cses.fi/problemset/task/1638
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
ll sum[1000+5][1000+5];
const int mod = 1e9 + 7;
void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a (n+1, vector<char> (n+1, '*'));
    FOR(i, 1, n+1){
        FOR(j, 1, n+1) {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == '*' || a[n][n] == '*') {
        cout << 0;
        return;
    }
    sum[1][1] = 1LL;
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            if (a[i][j] == '.') {
                if (a[i-1][j] != '*' && a[i][j-1] != '*') {
                    sum[i][j] = (sum[i-1][j] % mod + sum[i][j-1] % mod) % mod;
                    // sum[i][j] = sum[i-1][j] + sum[i][j-1];
                }
                else if (a[i-1][j] == '.') {
                    sum[i][j] = sum[i-1][j] % mod;
                    // sum[i][j] = sum[i-1][j];
                }
                else if (a[i][j-1] == '.'){
                    sum[i][j] = sum[i][j-1] % mod;
                    // sum[i][j] = sum[i][j-1];
                }
            }
        }
    }
    // FOR(i, 1, n+1) {
    //     FOR(j, 1, n+1) {
    //         cout << sum[i][j]<< " ";
    //     }
    //     cout << "\n";
    // }
    cout << sum[n][n] % mod;
}
