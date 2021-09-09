#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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
int n, k;
const int mod = 1e6;
int dp[150][150];

int dq(int n_i, int k_i) {
    if (k_i <= 0) return 0;
    if (k_i == 1) return dp[n_i][1] = 1;
    if (dp[n_i][k_i] != -1) return dp[n_i][k_i];
    else {
        int *ans = &dp[n_i][k_i];
        *ans = 0;
        FOR(i, 0, n_i+1) {
            *ans = (*ans + dq(n_i-i,k_i-1)) % mod;
        }   
        return *ans;
    }
}

void solve(){
    memset(dp, -1, sizeof dp);
    cout << dq(n, k) <<"\n";
    // FOR(i, n+1) {
    //     FOR(j, k+1) {
    //         cout << dp[i][j] << " \n"[j==k];
    //     }
    // }
}

int main()
{
    IOS;
    while(true) {
        cin >> n >> k;
        if (n == k && n == 0) break;
        solve();
    }
}