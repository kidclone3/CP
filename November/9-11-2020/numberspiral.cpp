#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

ll solve(ll x, ll y);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
}
ll solve(ll x, ll y)
{
    if (x == y && x == 1)
        return 1;
    ll mid, r;

    if (x == y)
    {
        r = (x - 1) * (x - 1);
        return (r + x);
    }
    if (x > y)
    {
        r = (x - 1) * (x - 1);
        mid = r + x;
        if (x % 2 == 0)
        {
            return mid + (x - y);
        }
        else
        {
            return mid - (x - y);
        }
    }
    else
    {
        r = (y - 1) * (y - 1);
        mid = r + y;
        if (y % 2 == 0)
        {
            return mid - (y - x);
        }
        else
        {
            return mid + (y - x);
        }
    }
}