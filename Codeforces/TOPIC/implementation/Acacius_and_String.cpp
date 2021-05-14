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
bool operator==(string a, string b) {
    if (a.size() != b.size()) return false;
    FOR(a.size()) {
        if(a[i] != b[i]) return false;
    }
    return true;
}
string st = "abacaba";
void solve();
pair<int, int> count_s(string s) {
    int pos=0;
    if (s.size() == 7) return {s == st, pos};
    int ans = 0;
    FOR(s.size() - 6) {
        string tmp = s.substr(i, 7);
        if (tmp == st) {
            pos = i;
            ans++;
        }
    }
    return {ans, pos};
    
}
int isEquals(string s, string st) {
    int ans = 0;
    FOR(7) {
        if (s[i] == st[i]) ans++;
        if (s[i] != st[i] && s[i] != '?') {
            return -1;
        }
    }
    return ans;
}
string out(string s, int index, string st) {
    string s1 = s.substr(0, index);
    string s2 = s.substr(index+7, s.size() - (index+7));
    EACH(it, s1) {
        if (it == '?') it ='z';
    }
    EACH(it, s2) {
        if (it == '?') it = 'z';
    }
    string ans = s1 + st + s2;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        solve();
    }
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos, appears;
    tie(appears, pos) = count_s(s);
    // cout << appears<<"\n";
    if (appears > 1) {        
        cout << "NO\n";
        return;
    }
    else if (appears == 1) {
        cout << "YES\n";
        cout << out(s, pos, st) <<'\n';
        return;
    }
    else {
        if (s.size() == 7 && isEquals(s, st) != -1) {
            cout << "YES\n";
            cout << out(s, 0, st) << '\n';
            return;
        }
        vector<int> ans;
        FOR(s.size() - 6) {
            string tmp = s.substr(i, 7);
            int tmp2 = isEquals(tmp, st);
            if (tmp2 != -1) {
                // cout << "YES\n";
                // cout << out(s, i, st) << '\n';
                // return;
                ans.pb(i);
            }
        }
        if (ans.empty()){
            cout << "NO\n";
            return;
        }
        else {
            EACH(it, ans) {
                string tmp = out(s, it, st);
                // int pos, appears;
                tie(appears, pos) = count_s(tmp);
                if (appears == 1) {
                    cout << "YES\n";
                    cout << tmp << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
// hfppoyeteeqfabac??ahjkrjdwa?a??bapnghixkweft