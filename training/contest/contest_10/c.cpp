#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = INT_MIN;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if (a[0] == mx && a[0] > a[1]){
        cout<<1<<'\n';
        return;
    }
    if (a[n-1] == mx && a[n-1] > a[n-2]){
        cout<<n<<'\n';
        return;
    }
    F_OR(i, 1, n-1, 1) {
        if (a[i] == mx) {
            if (a[i-1] < a[i] || a[i+1] < a[i]) {
                cout<<i+1<<'\n';
                return;

            }
        }
    }
    cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
