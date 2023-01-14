#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
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

void solve(){
    ll _sum, _xor;
    cin >> _sum >> _xor;
    ll _and = _sum - _xor;
    if (_and & 1) {
        cout << "0\n";
        return;
    }
    if (_xor == 0LL) {
        cout << "1\n";
        return;
    }
    _and >>= 1;
    ll cnt = 0LL;
    for (int i = 0; (1LL<<i) <= _xor; ++i) {
        if ((1LL<<i) & _xor) {
            if ((1LL<<i) & _and) {
                cout << 0;
                return;
            }
            cnt++;
        }
    }
    cnt = 1LL << cnt;
    if (_and == 0LL) cnt-=2;
    // cout << 2*cnt << '\n';
    cout << cnt << '\n';
}

int main()
{
    IOS;
    solve();
}