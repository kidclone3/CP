#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define vi vector<ll>
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
template <class T>
bool check_end(T a, T b) {
    a++;
    if (a==b) {
        return true;
    }
    return false;
}
vector<int> solve (vi a) {
    int n = a.size();
    vector<pair<ll, int>> aa;
    F_OR(i, 0, n, 1) {
        aa.pb(make_pair(a[i], i+1));
    }
    aa.pb({0,0});
    n++;
    sort(all(aa));
    vector<ll> dp(n, 0);
    vector<int> ans;
    F_OR(i, 1, n, 1) {
        dp[i] = dp[i-1] + aa[i].first;
    }
    ans.pb(aa[n-1].second);
    F_OR(i, n-2, 0, -1) {
        if(2*dp[i] >= dp[i+1]) {
            ans.pb(aa[i].second);
        }
        else break;
    }
    sort(all(ans));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        map<ll, ll> mp;
        ll mx = LLONG_MIN;
        F_OR(i, 0, n, 1) {
            cin >> a[i];
            mp[a[i]] ++;
        }
        vector<int> ans;
        ans = solve(a);
        cout<<ans.size()<<"\n";
        print(ans);
    }
}
