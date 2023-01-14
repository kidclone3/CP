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
const int maxM = 205; 
const int maxC = 25;
bool dp[maxC][maxM];
void solve(){
    // M = budget, C = numbers of garments
    int M, C; cin >> M >> C;
    vector<vector<int>> garments(C);
    FOR(C) {
        int n; cin >> n;
        FOR(j, n) {
            int tmp;
            cin >> tmp;
            garments[i].push_back(tmp);
        }
    }
    memset(dp, false, sizeof dp);
    // Initialize:
    EACH(it, garments[0]) {
        if (M >= it) {
            dp[0][M-it] = true;
        }
    }
    FOR(g, 1, C) {
        FOR(money, 0, M) if (dp[g-1][money]) {
            EACH(it, garments[g]) {
                if (money >= it) dp[g][money-it] = true;
            }
        }
    }
    int money = 0;
    for(; money <= M && !dp[C-1][money]; money++);
    if (money == M+1) cout << "no solution\n";
    else cout << M - money << '\n';
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        solve();
    }
}