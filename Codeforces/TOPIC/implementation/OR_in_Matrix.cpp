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
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout << (solve() ? "YES" : "NO");
    solve();
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m, 1));
    int b[n][m];
    FOR(i, n) {
        FOR(j, m) {
            cin >> b[i][j];
            if (b[i][j] == 0) {
                FOR(z, n) {
                    a[z][j] = 0;
                }
                FOR(z, m) {
                    a[i][z] = 0;
                }
            }
        }
    }
    // EACH(it, a) {
    //     print(it);
    // }
    FOR(i, n) {
        FOR(j, m) {
            int tmp = 0;
            FOR(z, n) {
                tmp |= a[z][j];
            }
            FOR(z, m) {
                tmp |= a[i][z];
            }
            if (tmp != b[i][j]) {
                cout << "NO";
                return;
            };
        }
    }
    cout << "YES\n";
    EACH(it, a) {
        print(it);
    }
}
