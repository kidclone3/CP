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
        cout <<it.first << " " << it.second <<"\n";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

void solve(){
    int n; cin >> n;
    string l, r; cin >> l >> r;
    vii ans;
    map<char, vi> mp1, mp2;
    FOR(n) mp1[l[i]].push_back(i), mp2[r[i]].push_back(i);
    vector<int> leftover1, leftover2;
    for(char ch = 'a'; ch <= 'z'; ++ch) {
        while(min(mp1[ch].size(), mp2[ch].size())) {
            ans.push_back({mp1[ch].back(), mp2[ch].back()});
            mp1[ch].pop_back();
            mp2[ch].pop_back();
        }
        while (mp1[ch].size() > 0) {
            leftover1.push_back(mp1[ch].back());
            mp1[ch].pop_back();
        }
        while (mp2[ch].size() > 0) {
            leftover2.push_back(mp2[ch].back());
            mp2[ch].pop_back();
        }
        // if (mp2[ch].size() > 0) leftover2.push_back({ch, mp2[ch].size()});
    }
    while(mp1['?'].size() && leftover2.size()) {
        ans.push_back({mp1['?'].back(), leftover2.back()});
        mp1['?'].pop_back();
        leftover2.pop_back();
    }
    while(mp2['?'].size() && leftover1.size()) {
        ans.push_back({leftover1.back(), mp2['?'].back()});
        mp2['?'].pop_back();
        leftover1.pop_back();
    }
    while(min(mp1['?'].size(), mp2['?'].size())) {
        ans.push_back({mp1['?'].back(), mp2['?'].back()});
        mp1['?'].pop_back();
        mp2['?'].pop_back();
    }
    
    cout << ans.size() <<'\n';
    // print(ans);
    EACH(it, ans)
        cout << it.first + 1 << " " << it.second + 1<< '\n';
    // cout << mp1['?'].size() << " " << mp2['?'].size() << "\n";
    // cout << leftover1.size() << " " << leftover2.size() << "\n";
}

int main()
{
    IOS;
    solve();
}