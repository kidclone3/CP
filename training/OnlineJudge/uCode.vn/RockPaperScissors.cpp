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
int isWin(string a, string b) {
    int ans = 0;
    F_OR(i, 0, a.size(), 1) {
        if (a[i] == b[i]) ans++;
        if (a[i] == 'R' && b[i] == 'S') ans+=2;
        if (a[i] == 'S' && b[i] == 'P') ans+=2;
        if (a[i] == 'P' && b[i] == 'R') ans+=2;
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
        ans+=isWin(ucoder, tmp);
    }
    cout << ans;
}
