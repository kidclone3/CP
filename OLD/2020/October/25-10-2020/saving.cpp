#include <bits/stdc++.h>
using namespace std;
void solve(vector<pair<int, int>> a, vector<int> x, int day, int n)
{
    vector<int> mp(n, 0);
    for (auto it : a)
    {
        for (int j = it.first - 1; j < it.second; j++)
        {
            mp[j]++;
        }
    }
    sort(mp.begin(), mp.end());
    for (auto it : x)
    {
        auto i = lower_bound(mp.begin(), mp.end(), it);
        if (i != mp.end())
        {
            int tmp = mp.end() - i;
            cout << tmp << '\n';
        }
        else
            cout << 0 << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("saving.inp", "r", stdin);
    freopen("saving.out", "w", stdout);
    int n, q, day;
    vector<pair<int, int>> inp;
    vector<int> x;
    cin >> n;
    cin >> day;
    for (int i = 0; i < day; i++)
    {
        int a, b;
        cin >> a >> b;
        inp.push_back({a, b});
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    solve(inp, x, day, n);
}