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
ll gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
void print2(vector<ll> vt, int j, ll ans) {
    if (j != 0) {
        cout<<j+1<<'\n';
    }
    else {
        cout<<1<<'\n';
    }
    F_OR(i, 0, j, 1) {
        cout<<vt[i] <<" ";
    }
    cout<<ans<<'\n';
}
void solve() {
    ll n, nn;
    cin >> n;
    vector<ll> vt;
    nn = n;
    for(ll i = 2; i*i <= n; ++i) {
        if (nn == 0) break;
        if (nn<=i) {
            vt.pb(nn);
            nn = 0;
            break;
        }
        while(nn!= 0 && nn%i==0) {
            vt.pb(i);
            nn/=i;
        }
    }
    if (nn > 0) {
        vt.pb(nn);
    }
    // print(vt);
    map<ll, int> mp;
    ll mx = 0;
    ll mx_val = 0;
    EACH(it, vt) {
        mp[it] ++;
        if (mx < mp[it]) {
            mx = mp[it];
            mx_val = it;
        }
    }
    // EACH(it, mp) {
    //     cout<<it.first <<" " <<it.second<<"\n";
    // }
    vector<ll> ans;
    nn = n;
    while(mp[mx_val] > 1) {
        ans.pb(mx_val);
        mp[mx_val]--;
        nn /= mx_val;
    }
    ans.pb(nn);

    cout<<ans.size()<<"\n";
    print(ans);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >>t;
    while(t--) {
        solve();
    }
}
