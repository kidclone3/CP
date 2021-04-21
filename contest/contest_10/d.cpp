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
    vector<bool> visited(n);
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }    
    vector<pair<int, int>> ans;
    int i = 0;
    visited[i] = 1;
    F_OR(j, 0, n, 1) {
        if (a[j] != a[i] && !visited[j]) {
            ans.pb({i+1, j+1});
            visited[j] = true;
        } 
    }
    F_OR(i, 1, n, 1) {
        if (!visited[i]) {
            F_OR(j, 0, n, 1) {
                if (a[j] != a[i] && visited[j]) {
                    ans.pb({i+1, j+1});
                    visited[i] = true;
                    break;
                }
            }
        }
        else {
            F_OR(j, 0, n, 1) {
                if (a[j] != a[i] && !visited[j]) {
                    ans.pb({i+1, j+1});
                    visited[j] = true;
                }
            }
        }
    }
    if (ans.size() == n-1) {
        cout<<"YES\n";
        EACH(it, ans){ 
            cout<<it.first << " " << it.second<<'\n';
        }
    }
    else {
        cout<<"NO\n";
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
