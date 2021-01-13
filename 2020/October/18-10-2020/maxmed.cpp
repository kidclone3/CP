#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll solve(vector<ll> a, ll k)
{
    sort(a.begin(), a.end());
    ll n = a.size();
    ll m = (n) / 2;
    vector<ll> d;
    d.push_back(0);
    for (ll i = 1; i <= m; i++)
    {
        ll tmp = i * (a[m + i] - a[m + i - 1]) + d[i - 1];
        d.push_back(tmp);
        if (tmp >= k)
            break;
    }
    if (d.back() >= k)
    {
        ll s = d.size();
        if (d[s - 1] == k)
            return a[m + s - 1];
        else
            return a[m + s - 2] + (k - d[s - 2]) / (s - 1);
    }
    else
    {
        k -= d[m];
        return a[n - 1] + k / (m + 1);
    }
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a;
    for (ll i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << solve(a, k);
}