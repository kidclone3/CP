#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
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
int isWin(vector<string> vt) {
    int ans = 0;
    F_OR(i, 0, vt[0].size(), 1) {
        map<char, int> mp;
        F_OR(j, 0, vt.size(), 1) {
            mp[vt[j][i]] ++;
        }
        vector<pair<char,int>> p;
        EACH(it, mp) {
            
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string ucoder;
    cin >> ucoder;
    int q;
    cin >> q;
    vector<string> myvector;
    ll ans = 0;
    F_OR(i, 0, q, 1) {
        string tmp;
        cin >> tmp;
        myvector.pb(tmp);
    }
    ans = isWin(myvector);
    cout << ans;
}
