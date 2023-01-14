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
    int a[n];
    int ans = 0;
    map<int, int> mp;
    F_OR(i, 0, n ,1) {
        cin >> a[i];
        mp[a[i]]++;
    }
    EACH(it, mp) {
        if (it.second == 1) {
            F_OR(i, 0, n, 1) {
                if (a[i] == it.first) {
                    cout<<i+1<<'\n';
                    return;
                }
            }
        }
    }

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
