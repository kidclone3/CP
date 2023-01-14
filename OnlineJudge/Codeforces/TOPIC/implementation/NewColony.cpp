// https://codeforces.com/problemset/problem/1481/B
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
    int a[n+1];
    FOR1(i, n) {
        cin >> a[i];
    } 
    while(k) {
        bool stopped = false;
        int last = 0;
        F_OR(i, 1, n, 1) {
            if (a[i] < a[i+1]) {
                a[i] ++;
                k--;
                if (k==0) last = i;
                stopped = true;
                break;
            }
        }
        if (k==0) {
            cout << last <<'\n';
            return;
        }
        if (stopped) continue;
        cout << "-1\n";
        return;
    }
    // cout << "-1\n";
}