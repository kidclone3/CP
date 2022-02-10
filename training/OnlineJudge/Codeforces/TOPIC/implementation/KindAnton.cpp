// https://codeforces.com/problemset/problem/1333/B
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
    int a[n], b[n];
    map<int, int> mp;
    FOR(i, n) {
        cin >> a[i];
    } 
    FOR(i, n) {
        cin >> b[i];
    }
    if (a[0] != b[0]) {
        cout << "NO\n";
        return;
    }
    FOR(i, n) {
        if (a[i] == b[i]) {
            mp[a[i]]++;
            continue;
        }
        if (a[i] > b[i]) {
            if (mp[-1] == 0) {
                cout << "NO\n";
                return;
            }
        }
        if (a[i] < b[i]) {
            if (mp[1] == 0) {
                cout << "NO\n";
                return;
            }
        }
        mp[a[i]] ++;
    }
    cout << "YES\n";
}