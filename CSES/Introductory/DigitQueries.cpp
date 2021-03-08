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
ll power(ll base, ll k) {
    if (k==1) return base;
    if (k==0) return 1;
    ll tmp = power(base, k/2);
    if (k&1) {
        return tmp*tmp*base;
    }
    else return tmp*tmp;
}
char solve(ll k) {
    int n = 1;
    ll up= power(10, n-1) * 9 * n;
    while (k>=up) {
        k -= up;
        n++;
        up= power(10, n-1) * 9 * n;
    }
    if (k==0) return '9';
    ll down = power(10, n-1);
    ll ans = down + (k-1) / n;
    k -= (k-1)/n * n;
    string s = to_string(ans); 
    // cout << s <<"\n";
    return s[k-1];

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("inp.txt", "r", stdin);
    // freopen("2.txt", "w", stdout);
    int q;
    cin >> q;
    while(q--) {
        ll k;
        cin >> k;
        cout << solve(k) << "\n";
    }
}
