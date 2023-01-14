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

void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
void solve() {
    int n;
    cin >> n;
    vector <int> a(n+1);
    int sum = 0;
    F0R(i, 1, n+1) {
        cin >> a[i];
        sum += a[i];
    }   
    sort(all(a));
    vector<int> dp(n+1, 0);
    F_OR(i, 1, n+1, 1) {
        dp[i] = dp[i-1] + a[i];
    }
    F_OR(i, n, 0, -1) {
        if (dp[i-1] < (sum - dp[i-1])) {
            cout << n-i + 1<< "\n";
            return;
        }
    }
}