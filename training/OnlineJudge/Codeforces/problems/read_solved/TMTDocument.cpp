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
bool solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}
bool solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> t, m;
    FOR(i, n) {
        if (s[i] == 'T') {
            t.pb(i);
        }
        else {
            m.pb(i);
        }
    }
    if (t.size() != 2 * m.size()) {
        return false;
    }
    FOR(i, m.size()) {
        if (m[i] < t[i] || m[i] > t[i+m.size()]) {
            return false;
        }
    }
    return true;
}