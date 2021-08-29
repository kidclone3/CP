#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<ll>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (ll i=(a); (step)>0? i<(b) : i>(b); i+=(step))
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
bool check(ll a, ll b) {
    return !((a+b) & 1);
    
}
ll solve(ll n) {
    ll mn = LLONG_MAX;
    for(ll i = 1; i*i <n; ++i) {
        if (n%i==0) {
            if (check(i, n/i)) {
                ll tmp = ((n/i-i)/2)*((n/i-i)/2);
                mn = min(mn, tmp);
            }
        }
    }
    if (mn!=LLONG_MAX) return mn;
    else return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    // cthuc n = m^2 - x^2 = (m-x)*(m+x)
    
    while(t-- ){
        ll x;
        cin >> x;
        cout<<solve(x) <<'\n';
    }
}
