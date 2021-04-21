#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
const int N = 1000+5;
char a[N][N];
int dp[N][N];
void solve();
void check(int i, int j, int ans) {
    if (a[i][j] == '.') {
        dp[i][j] = ans;
    }
    else {
        dp[i][j] = -1;
    }
}
void bfs(int i, int j, int ans, int n, int m) {
    if (a[i][j] == '#' || dp[i][j]!=0) {
        return;
    }
    else {
        check(i, j, ans);
        if (i+1 <= n) {
            bfs(i+1, j, ans, n, m);
        }   
        if (j+1 <= m) {
            bfs(i, j+1, ans, n, m);
        }
        if (i>1) {
            bfs(i-1, j, ans, n, m);
        }
        if (j>1) {
            bfs(i, j-1, ans, n, m);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
void solve() {
    int n, m;
    cin >> n >> m;
    F0R(i, 1, n+1) {
        F0R(j, 1, m+1) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    F0R(i, 1, n+1) {
        F0R(j, 1, m+1) {
            if (a[i][j] == '.' && dp[i][j] == 0) {
                ans++;
                bfs(i, j, ans, n, m);
            }
        }
    }
    // F0R(i, 1, n+1) {
    //     F0R(j, 1, m+1) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout << "\n";
    // }
    cout << ans;
}