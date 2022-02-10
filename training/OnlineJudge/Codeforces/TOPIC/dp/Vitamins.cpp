// https://codeforces.com/gym/302977/problem/C
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
vector<string> split(string s) {
    stringstream ss(s);
    vector<string> ans;
    string tmp;
    while(ss >> tmp) {
        ans.push_back(tmp);
    }
    return ans;
}
int main()
{
    IOS;
    solve();
}
void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    FOR(n) {
        int a;
        string b;
        cin >> a >> b;
        sort(all(b));
        if (mp.count(b))  {
            mp[b] = min(mp[b], a);
        }
        else {
            mp[b] = a;
        }
    } 
    vector<string> ch[10];
    ch[0] = {"A B C"};
    ch[1] = {"A BC", "B AC", "C AB"};
    ch[2] = {"AB AC", "AB BC", "AC BC"};
    ch[3] = {"ABC"};
    int ans = 1e9;
    FOR(4) {
        EACH(it1, ch[i]) {
            vector<string> splt = split(it1);
            int tmp = 0;
            EACH(it2, splt) {
                if (mp[it2] == 0) {
                    tmp = 1e9;
                    break;
                }
                else {
                    tmp += mp[it2];
                }
            }
            ans = min(ans, tmp);
        }
    }

    cout << (ans != 1e9 ? ans : -1);
}
