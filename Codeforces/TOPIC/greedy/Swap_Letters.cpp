// https://codeforces.com/contest/1215/problem/C
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
void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt = 0;
    set<int> a, b;
    FOR(i, n) {
        if (s1[i] != s2[i]) {
            cnt++;
            if (s1[i] == 'a') {
                a.insert(i);
            }
            else {
                b.insert(i);
            }
        }
    }
    if (cnt & 1) {
        cout << "-1";
        return;
    }
    vector<pair<int, int>> ans;
    if (a.size() & 1) {
        int tmp = *a.begin();
        ans.push_back({tmp + 1, tmp + 1});
        a.erase(tmp);
        b.insert(tmp);
    }
    while(!a.empty() || !b.empty()) {
        if (!a.empty()) {
            int fi, se;
            fi = *a.begin();
            se = *a.upper_bound(fi);
            ans.push_back({fi + 1, se + 1});
            a.erase(fi);
            a.erase(se);
        }
        else {
            int fi, se;
            fi = *b.begin();
            se = *b.upper_bound(fi);
            ans.push_back({fi + 1, se + 1});
            b.erase(fi);
            b.erase(se);
        }
    }
    cout << ans.size() << "\n";
    for(auto it : ans) {
        cout << it.first << " " << it.second <<"\n";
    }
}
