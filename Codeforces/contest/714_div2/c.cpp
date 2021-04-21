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
string inc(string &n);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}
string inc(string &n) {
    vector<int> vt;
    F_OR(i, n.size()-1, -1, -1) {
        vt.pb(n[i] - '0' + 1);
    }
    string s="";
    EACH(it, vt) {
        s= to_string(it) + s;
    }
    
    return s;
}
vector<ll> vt(string s) {
    vector<ll> vt(10);
    EACH(it, s) {
        vt[it-'0'] ++;
    }
    return vt;
}
void solve() {
    string n;
    cin >> n;
    // cout << inc(n) <<"\n";
    FOR(i, 100) {
        n = inc(n);
        // cout << n.size() <<"\n";
    }
    cout << n.size() <<"\n";
    vector<ll> v = vt(n);
    print(v);
}