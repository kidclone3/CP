// https://codeforces.com/problemset/problem/1332/A
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
        cout << (solve() ? "YES\n" : "NO\n");
    }
}
bool solve() {
    ll a, b, c, d;
    ll x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    x += b-a;
    y += d-c;
    // Phan thua theo truc x phai nam trong [x1, x2]
    // Phan thua theo truc y phai nam trong [y1, y2]
    if (a+b > 0 && x1 == x2) {
        return false;
    }
    else if (c + d > 0 && y1 == y2) {
        return false;
    }
    else if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
        return true;
    }
    else return false;
}