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
    int count1 = 0;
    vector<int> a(n);
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        if (a[i]) count1++;
    }
    if (count1 == 1) {
        cout<< 0 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < n-1; ) {
        if (a[i] == 0) {
            i++;
            continue;
        }
        else {
            int j = i+1;
            while(j < n && a[j]== 0) j++;
            if (j<n) {
                ans+= (j-i-1);
                i = j;
            }
            else {
                break;
            }
        }
    }
    cout<<ans<<'\n';
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
