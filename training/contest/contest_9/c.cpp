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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    } 
    vector<ll> dp(n, 0);
    sort(all(a));
    ll sum = 0;
    ll ans = 0;
    // int l = 0;
    // F_OR(r, 0, n, 1) {
    //     sum+= a[r];
    //     while (sum > t) {
    //         sum -= a[l];
    //         l++;
    //     }
    //     if (sum <= t) {
    //         ans = max(ans, sum);
    //     }
    // }
    for (int r = n-1; r>=0; --r) {
        ll tmp = t - a[r];
        if (tmp >= 0) {
            dp[r] += a[r];
            tmp -= a[r];
            while (tmp >= 0)
            {
                auto it = upper_bound(all(a), tmp);
                if (it == a.begin()) {
                    break;
                }
                else {
                    it--;
                    tmp -= *it;
                    dp[r] += *it;
                }
            }
            
        }
            ans = max (ans, dp[r]);
    }
    cout<<ans;
}
