#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

ll solve(VI s, VI v, VI p);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        VI s, v, p;
        for (int i = 0; i < n; i++)
        {
            int Si, Vi, Pi;
            cin >> Si >> Pi >> Vi;
            s.PB(Si);
            v.PB(Vi);
            p.PB(Pi);
        }
        cout << solve(s, v, p) << '\n';
    }
}
ll solve(VI s, VI v, VI p)
{
    ll M = 0;
    for (int i = 0; i < s.size(); i++)
    {
        M = max(M, v[i] * (ll)(p[i] / (s[i] + 1)));
    }
    return M;
}