#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long
#define VI vector<ll>

long long solve(VI a);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("a.inp", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    VI inp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        inp.PB(tmp);
    }
    cout << solve(inp);
}
long long solve(VI a)
{
    int n = a.size();
    map<ll, int> p;
    for (auto it : a)
    {
        p[it]++;
    }
    int now;
    long long M;
    now = M = 0;
    for (auto i = p.rbegin(); i != p.rend(); i++)
    {
        i->second += now;
        now = i->second;
    }
    for (auto it : p)
    {
        M = max(M, (long long)(it.second * it.first));
    }
    return M;
}