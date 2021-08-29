#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
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
bool solve(ll x) {
    ll l = 1LL;
    ll r = 10000LL;
    while(l<=r) {
        if ((l*l*l + r*r*r) == x) return true;
        if ((l*l*l + r*r*r) < x) {
            l++;
        }
        else {
            r--;
        }
    }
    return false;
}
int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // bruteforce;
    int t;
    cin >> t;
    while(t--) {
        ll x; 
        cin >> x;
        
        if (solve(x)) {
            cout<<"YES\n";
        }
        else {
            cout<< "NO\n";
        }
    }
}
