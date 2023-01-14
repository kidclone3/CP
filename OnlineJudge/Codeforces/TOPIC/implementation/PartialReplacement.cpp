// https://codeforces.com/problemset/problem/1506/B
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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int i = 0;
    while(i < s.size() && s[i] != '*') i++;
    if (i == s.size()) {
        cout << "0\n";
        return;
    }
    else ans++;
    int last = s.size() - 1;
    while (last >= 0 && s[last] != '*') last--;
    if (last != i) ans++;
    else {
        cout << ans <<'\n';
        return;
    }
    for (;i < s.size();) {

        // tim xem vi tri * dau tien.
        int j = i+k;
        if (j >= last) break;
        while(j > i && s[j] != '*') j--;
        ans++;
        i = j;
    }
    cout << ans << "\n";
}