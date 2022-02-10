// https://codeforces.com/problemset/problem/489/C
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
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
    solve();
}
void solve() {
    int m, s;
    cin >> m >> s;
    if (9 * m < s) {
        cout << "-1 -1";
        return;
    }
    if (s == 0) {
        if (m == 1) {
            cout << "0 0";
            return;
        }
        else {
            cout << "-1 -1";
            return;
        }
    }
    string mx, mn;
    mx = mn = "";
    int tmp = s;
    int siz = 0;
    while(tmp) {
        if (tmp >= 9) {
            mx += '9';
            tmp -= 9;
            siz ++;
        }
        else {
            mx += tmp + '0';
            tmp = 0;
            siz++;
        }
    }
    while(siz != m) {
        mx += '0';
        siz++;
    }
    // now is mn.
    bool f = false;
    if (mx.back() == '0') {
        mn = "1";
        f = true;
    }
    else {
        mn += mx.back();
    }
    for (int i = mx.size()-2; i >= 0; --i) {
        if (f && mx[i] != '0') {
            mn += mx[i] - 1;
            f = false;
        }
        else {
            mn += mx[i];
        }
    }
    cout << mn << " " << mx;
}
