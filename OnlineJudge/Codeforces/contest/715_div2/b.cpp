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
    string s;
    cin >> s;
    if (s.front() == 'M' || s.back() == 'M') {
        cout << "NO\n";
        return;
    }
    int count = 0;
    set<int> t, m;
    FOR(i, n) {
        if (s[i] == 'T') {
            t.insert(i);
        }
        else {
            m.insert(i);
        }
    }
    for (auto it = t.begin(); it != t.end(); ) {
        if (t.empty() || m.empty()) break;
        auto it_m = m.end();
        it_m--;
        auto it_t = t.end();
        it_t--;
        if (*it < *it_m && *it_m < *it_t) count ++;
        else {
            cout << "NO\n";
            return;
        }
        t.erase(it);
        t.erase(it_t);
        m.erase(it_m);
        if (t.empty() || m.empty()) break;
        it = t.begin();
    }
    (count * 3 == n) ? (cout << "YES\n") : (cout << "NO\n");
    

}