#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define VI vector<ll>

ll solve(VI a);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("gentroi.inp", "r", stdin);
    freopen("gentroi.out", "w", stdout);
    int n;
    cin >> n;
    VI a;
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << solve(a) << '\n';
}
ll solve(VI a)
{
    VI sum;
    ll M = -1e18;
    for (auto it : a)
    {
        if (sum.empty())
        {
            sum.push_back(it);
        }
        else
        {
            sum.push_back(it + sum.back());
        }
    }
    for (int l = 3; l < a.size(); l += 3)
    {
        for (int i = l - 1; i < a.size(); i++)
        {
            if (i == l - 1)
            {
                M = max(M, sum[i]);
            }
            else
            {
                M = max(M, sum[i] - sum[i - l]);
            }
        }
    }
    return M;
}