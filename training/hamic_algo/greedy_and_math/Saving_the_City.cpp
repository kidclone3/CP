#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
void solve();
int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}
void solve() {
    ll a, b;
    cin >> a >> b;
    string s; cin >> s; 
    vector<pii> c; // Các cặp liên thông
    for (int i = 0; i < (int) s.size();) {
        if (s[i] == '0') {
            i++;
            continue;
        }
        int j = i;
        while(j < (int) s.size() && s[j+1] == '1') {
            j++;
        }
        c.push_back({i, j});
        i = j+1;
    }
    // printPair(c);
    int n = c.size();
    vi dis;
    FOR(i, 1, n) {
        dis.push_back(c[i].first - c[i-1].second - 1);
    }
    sort(all(dis));
    // print(dis);
    ll mn = a * n;
    ll sum = 0;
    FOR(i, (int) dis.size()) {
        sum += (ll) dis[i];
        mn = min(mn, b*sum + a * (n-i-1));
    }
    cout << mn <<"\n";
}
