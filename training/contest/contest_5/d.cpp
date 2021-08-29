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
const ll N = 2*1e5+5;
ll a[N];
ll c2(ll n) {
    return (ll) n*(n-1)/2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll, ll> mp1, mp2;
    F_OR(i, 0, n,1) {
        cin >> a[i];
        mp1[a[i]]++; // Tinh so phan tu tai vi tri I.
    }
    // Ap dung cthuc nC2.
    ll ans = 0;
    EACH(it, mp1) {
        if(it.second>=2) {
            mp2[it.first] = c2(it.second);
            ans+=c2(it.second);
        }
    }
    F_OR(k, 0, n, 1) {
        mp1[a[k]]--;
        if (mp1[a[k]] <= 1) {
            cout<<ans-mp2[a[k]] <<'\n';
        }
        else {
            cout<<ans-mp2[a[k]] + c2(mp1[a[k]]) <<"\n";
        }
        mp1[a[k]]++;
    }
    
}
