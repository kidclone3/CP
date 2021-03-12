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
ll a, b;
ll k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> k;
    ll ans = 0;
    ll xa = ceil(sqrt(a));
    ll ya = ceil(pow(a, 1.0/3));
    ll xb = floor(sqrt(b));
    ll yb = floor(pow(b, 1.0/3));
    for (ll i = xa; i<= xb; ++i) {
        for (ll j = ya; j<= yb; ++i) {
            if (abs(i - j) <=k) {
                ans++;
            }
        }
    }
    cout<<ans;
}