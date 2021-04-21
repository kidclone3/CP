#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
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
void format(string & a) {
    while(a.size() >= 3 && a[0] == 'W' && a[1] == 'U' && a[2] == 'B') {
        a.erase(a.begin(), a.begin() + 3);
    }
    while(a.size() >= 3 && a[a.size() - 3] == 'W' && a[a.size() - 2] == 'U' && a[a.size()-1] == 'B')
        {
            a.erase(a.begin() + (a.size() -3), a.end());
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
void solve() {
    string s;
    cin >> s;
    format(s);
    string tmp = "";
    vector<string> ans;
    FOR(i, s.size()) {
        if (i < s.size() - 3 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i = i+2;
            if (tmp != "") {
                ans.pb(tmp);
            }
            tmp ="";
        }
        else {
            tmp+=s[i];
        }
    }
    if (tmp != "") ans.pb(tmp);
    print(ans);
}