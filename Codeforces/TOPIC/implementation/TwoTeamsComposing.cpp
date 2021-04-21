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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    FOR(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 0;
    EACH(it, mp) {
        if (it.second >= 1) {
            if (it.second > mp.size() - 1) {
                ans = max(ans, (int) mp.size() - 1);
            }
            else {
                ans = max(ans, it.second);
            }
        }
    }
    cout << ans <<'\n';
}