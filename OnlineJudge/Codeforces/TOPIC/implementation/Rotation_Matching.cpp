// https://codeforces.com/problemset/problem/1365/C
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
    int n;
    cin >> n;
    map<int, int> mp1, mp2, mp3;
    FOR(n) {
        int tmp;
        cin >> tmp;
        mp1[tmp] = i;
    }
    FOR(n) {
        int tmp2;
        cin >> tmp2;
        mp2[tmp2] = i;
    }
    EACH(it, mp1) {
        if (it.second >= mp2[it.first]) {
            mp3[it.second - mp2[it.first]]++;
        }
        else {
            mp3[it.second + n - mp2[it.first]]++;
        }
    }
    int mx = -1e9;
    EACH(it, mp3) {
        mx = max(mx, it.second); 
    }
    cout << mx;
}
