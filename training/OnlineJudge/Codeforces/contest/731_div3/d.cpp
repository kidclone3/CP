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
// int leftMost(int x) {
//     int i = 0;
//     while(x) {
//         x >>= 1;
//         i++;
//     }
//     if (i >= 30) return INT_MAX;
//     return (1<<i);
// }
int mostAnd(int a, int b) {
    if (b < a) {
        b += (1<<30);
    }
    int i = 0;
    int ans = 0;
    for(; (1 << i) <= a; ++i) {
        if (a&(1<<i) && !(b & (1<<i))) {
            ans += (1<<i);
        }
    }
    return ans;
}
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
}
void solve() {
    int n;
    cin >> n;
    vi x(n), y(n);
    y[0] = 0;
    FOR(n) cin >> x[i];
    FOR(i, 1, n) {
        int tmp = x[i-1] ^ y[i-1];
        if ((tmp & x[i]) == tmp) {
            y[i] = 0;
            continue;
        }
        // int tmp1 = leftMost(x[i]);
        int tmp2 = mostAnd(tmp, x[i]);
        y[i] = min(tmp ^ x[i], tmp2);
        // cout << tmp << " " << tmp2 << "\n";
    } 
    print(y);
}
