#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<ll>
#define ll long long
#define all(x) x.begin(), x.end()
#define BUG(x)                            \
    {                                     \
        cout << #x << " = " << x << "\n"; \
    }

template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
}
ll n, t;
vi a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.pb(tmp);
    }
    sort(all(a));
    ll lo, hi, mid, ans;
    lo = 0;
    hi = 1e18;
    ans = 0;
    // use binary search to find the smallest time
    // possible
    while (lo <= hi)
    {
        ll sum = 0; // total of products.
                    // if sum>t then break;
        mid = (lo + hi) / 2;
        for (ll i : a)
        {
            sum += mid / i;
            if (sum >= t)
                break;
        }
        if (sum >= t)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
        // BUG(mid);
    }
    cout << ans;
}