// https://codeforces.com/problemset/problem/463/B
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
    solve();
}
void solve() {
    int n;
    cin >> n;
    int a[n+1];
    int ans = 0;
    int h = 0;
    FOR1(i, n) {
        cin >> a[i];
    } 
    ans = a[1];
    a[0] = a[1];
    // h = a[0];
    F_OR(i, 0, n, 1) {
        if (a[i] - a[i+1] >= 0) {
            h+= a[i] - a[i+1];
        }
        else {
            if (a[i] + h >= a[i+1]) {
                h -= a[i+1] - a[i];
            }
            else {
                ans+= a[i+1] - a[i] - h;
                h = 0;
            }
        }
    }
    cout << ans;
}