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
int n, m;
void solve();
int backtrack_itr(int i, int sum, vector<vi> a);

int main()
{
    IOS;
    solve();   
}
int backtrack_itr(int i, int sum, vector<vi> a) {
    int sum1 = sum;
        for(int j = 0; (1 << j) <= i; ++j) {
            if ((1<<j) & i) {
                if (j < n) {
                    // neu < n thi la chuyen doi o rows
                    FOR(z, m) {
                        sum1 += (!a[j][z] ? 1 : -1);
                        a[j][z] ^= 1;
                    }
                }
                else {
                    FOR(z, n) {
                        sum1 += (!a[z][j-n] ? 1 : -1);
                        a[z][j-n] ^= 1;
                    }
                }
            }
        }
    return sum1;
}
void solve() {
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    int sum = 0;
    FOR(n) {
        FOR(j, m) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    int mx = sum;
    for (int i = 1; i < (1<<(n+m)); i++)
    {
        mx = max(mx, backtrack_itr(i, sum, a));
    }
    cout << mx;
}
