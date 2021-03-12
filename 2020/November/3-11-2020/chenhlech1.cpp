#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll a[], int au, int av);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll a[n + 1];
    a[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int b1, b2;
        cin >> b1 >> b2;
        cout << solve(a, b1, b2) << '\n';
    }
}

ll solve(ll a[], int u, int v)
{
    ll res = LONG_LONG_MAX;
    register int l, r, mid;
    l = u;
    r = v;
    while (l <= r)
    {

        mid = (l + r) / 2;
        ll tmp = abs(a[v] - a[mid] - (a[mid] - a[u - 1]));
        res = min(tmp, res);
        if (a[v] - a[mid] > a[mid] - a[u - 1])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}
