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
ll gcd (ll a, ll b) {
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> vt;
    ll a, b, c;
    cin >> a >> b >> c;
    vt.pb(a);
    vt.pb(b);
    vt.pb(c);
    sort(all(vt));
    ll tmp = gcd(vt[2], vt[1]);
    cout << gcd(max(vt[0], tmp), min(vt[0], tmp));
}
