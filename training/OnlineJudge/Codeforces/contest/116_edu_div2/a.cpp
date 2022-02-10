#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
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

string change(vector<int> pos, string s) {
    EACH(i, pos) {
        s[i] = s[i] == 'a' ? 'b' : 'a';
    }
    return s;
}
bool check(string s) {
    int ab, ba; ab = ba = 0;
    FOR(i, s.size() - 1) {
        string tmp = s.substr(i, 2);
        if (tmp == "ab") ab++;
        else if (tmp == "ba") ba++;
    }
    return ab==ba;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    int ab, ba;
    ab = ba = 0;

    for(int i = 0; i < n-1; i++) {
        string tmp = s.substr(i, 2);
        if (tmp == "ab") ab++;
        else if (tmp == "ba") ba++;
    }
    // cout << ab << " " << ba << "\n";
    if (ab == ba || n == 1) {
        cout << s << "\n";
        return;
    }
    vector<vi> pos = {{0}, {n-1}, {0,1}, {n-2, n-1}};
    EACH(it, pos) {
        string tmp = change(it, s);
        if (check(tmp)) {
            cout << tmp << "\n";
            return;
        }
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--)
        solve();
}