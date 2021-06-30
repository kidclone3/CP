#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define pii pair<int,int>
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
        cout << "{" << it.first << ", " << it.second << "}, ";
    }
    cout << "\n";
};
int operator/ (int a, pii b) {
    double tmp = 1.0*b.first/b.second;
    return (int) ceil(a/tmp);
}
pii operator-= (pii& _p1, const pii& _p2) {
    int top = _p1.first * _p2.second - _p1.second * _p2.first;
    int bot = _p1.second * _p2.second;
    int tmp = __gcd(top, bot);
    top /= tmp, bot /= tmp;
    _p1 = {top, bot};
    return {top, bot};
}
void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    pii inp;
    cin >> inp.first >> inp.second;
    vector<pii> ans;
    if (inp.first == 1) ans.push_back(inp);
    else {
        while(true) {
            int bot = 1 / inp;
            ans.push_back({1, bot});
            inp -= {1, bot};
            if (inp.first == 1) {
                ans.push_back(inp);
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    print(ans);
}
