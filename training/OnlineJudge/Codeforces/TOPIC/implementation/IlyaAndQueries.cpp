#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
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
    // IO;
    solve();
}
void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> dp(s.size() + 1, 0);
    FOR1(i, s.size()-1) {
        if (s[i-1] == s[i]) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            dp[i] = dp[i-1];
        }
    } 
    FOR(i, n) {
        int a, b;
        cin >> a >> b;
        cout << dp[b-1] - dp[a-1] << "\n";
    }  
    // print(dp);
}