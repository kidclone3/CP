// https://codeforces.com/problemset/problem/1367/D
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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int a[m];
    queue<int> pos_0;
    FOR(i, m) {
        cin >> a[i];
        if (a[i] == 0) pos_0.push(i);
    } 
    string t(m, '0');
    sort(s.begin(), s.end());
    char last =' ';
    int still = m;
    while (still--)
    {
        // while(s.back() != s[s.size() - pos_0.size()]) s.pop_back();
        if (pos_0.empty()) {
            FOR(i, m) {
                if (a[i] == 0 && t[i] == '0') pos_0.push(i);
            }
            while((!pos_0.empty() && (s.back() != s[s.size() - pos_0.size()])) || s.back() == last) s.pop_back();
        }
        else {
            while(s.back() != s[s.size() - pos_0.size()]) s.pop_back();
        }
        t[pos_0.front()] = s.back();
        last = s.back();
        s.pop_back();
        // pos_0.pop();
        FOR(i, m) {
            if (a[i] != 0) {
                a[i]-= abs(i - pos_0.front());
                // if (a[i] == 0) pos_0.push(i);
            }
        }
        pos_0.pop();
    }
    cout << t << "\n";
    
}
