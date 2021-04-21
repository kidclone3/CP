#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i)
#define F0R(i, a, b) for (int i = (a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
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
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> h, e, l, o;
    FOR(i, n)
    {
        if (s[i] == 'h')
            h.pb(i);
        if (s[i] == 'e')
            e.pb(i);
        if (s[i] == 'l')
            l.pb(i);
        if (s[i] == 'o')
            o.pb(i);
    }
    if (h.empty() || e.empty() || l.empty() || o.empty())
    {
        cout << "NO";
        return;
    }
    bool failed = false;
    int it = h[0];
    auto i1 = upper_bound(all(e), it);
    if (i1 == e.end())
        failed = true;
    auto i2 = upper_bound(all(l), *i1);
    if (i2 == l.end())
        failed = true;
    auto i3 = upper_bound(all(l), *i2);
    if (i3 == l.end())
        failed = true;
    auto i4 = upper_bound(all(o), *i3);
    if (i4 == o.end())
        failed = true;
    (failed) ? (cout << "NO") : (cout << "YES");
}