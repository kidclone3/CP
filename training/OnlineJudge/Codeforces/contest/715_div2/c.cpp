#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
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
bool cmp(pair<int, ll> a, pair<int, ll> b) {
    if (a.first>b.first) {
        return true;
    }
    else {
        if (a.first < b.first) {
            return false;
        }
        else {
            return a.second < b.second;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, int> mp;
    FOR(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int, ll>> vt;
    EACH(it, mp) {
        vt.pb({it.second, it.first});
    }
    sort(all(vt), cmp);
    vector<ll> ans;
    EACH(it, vt) {
        int nn = it.first;
        while(nn--) {
            ans.pb(it.second);
        }
    }
    ll sum = 0;
    ll mn = LLONG_MAX;
    ll mx = LLONG_MIN;
    EACH(it, ans) {
        mn = min(mn, it);
        mx = max(mx, it);
        sum += mx - mn;
    }
    cout << sum;
}