// https://codeforces.com/contest/1439/problem/A1
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
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
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

void solve(){
    int n, m; cin >> n >> m;
    string s[n];
    vector<vi> ans;
    FOR(n) cin >> s[i];

    auto fun1 = [&](int x, int y) {
        if (x + 1 >= n || y+1 >= m) return false;
        vi tmp = {x+2, y+1, x+1, y+1, x+1, y+2};
        ans.push_back(tmp);
        tmp = {x+1, y+1, x+2, y+1, x+2, y+2};
        ans.push_back(tmp);
        tmp = {x+1, y+1, x+1, y+2, x+2, y+2};
        ans.push_back(tmp);
        return true;
    };
    auto fun2 = [&](int x, int y) {
        if (x + 1 >= n || y-1 < 0 || x-1 < 0) return false;
        vi tmp = {x+1, y-1+1, x+1, y+1, x+1+1, y+1};
        ans.push_back(tmp);
        tmp = {x+1, y+1, x+1+1, y+1, x+1, y+1+1};
        ans.push_back(tmp);
        tmp = {x+1, y+1, x-1+1, y+1, x-1+1, y+1+1};
        ans.push_back(tmp);
        return true;
    };

    auto fun3 = [&](int x, int y) {
        if (x+1 >= n || y+1 >= m || y-1 < 0) return false;
        vi tmp = {x+1, y-1+1, x+1, y+1, x+1+1, y+1};
        ans.push_back(tmp);
        tmp = {x+1, y+1, x+1, y-1+1, x+1+1, y-1+1};
        ans.push_back(tmp);
        tmp = {x+1, y+1, x+1, y+2, x, y+1};
        ans.push_back(tmp);
        return true;
    };
    
    auto fun4 = [&](int x, int y) {
        if (x-1 < 0 || y-1 < 0) return false;
        vi tmp = {x, y+1, x+1, y+1, x+1, y};
        ans.push_back(tmp);
        tmp = {x, y, x+1, y, x+1, y+1};
        ans.pb(tmp);
        tmp = {x, y, x, y+1, x+1, y+1};
        ans.pb(tmp);
        return false;
    };
    FOR(i, n) FOR(j, n) {
        if (s[i][j] == '1') {
            if (fun1(i, j)) continue;
            else if (fun2(i, j)) continue;
            else if (fun3(i, j)) continue;
            else fun4(i, j);
        }
    }
    cout << ans.size() << "\n";
    EACH(it, ans) {
        EACH(it2, it) cout << it2 << " ";
        cout << '\n';
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}