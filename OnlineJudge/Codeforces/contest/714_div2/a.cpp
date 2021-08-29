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
void inputIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // inputIO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    if (n <= 2 && k == 0) {
        F0R(i, 1, n+1) {
            cout << i << " ";
        }
        cout<<"\n";
        return;
    }
    if (k > (n-1) / 2) {
        cout << "-1\n";
        return;
    }
    map<int, int> mp;
    queue<int> peak;
    FOR(i, k) {
        peak.push(n-i);
        mp[n-i] = 1;
    }
    vector<int> ans;
    int j = 1;
    FOR(i, n) {
        if (i&1 && !peak.empty()) {
            ans.pb(peak.front());
            peak.pop();
        }
        else {
            ans.pb(j++);
        }
    }
    print(ans);
    
}