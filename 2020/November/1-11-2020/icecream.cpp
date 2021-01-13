#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

bool compair(pair<int, int> a1, pair<int, int> a2);
pair<int, int> solve(VI c, int money);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        VI c;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            c.push_back(tmp);
        }
        auto res = solve(c, m);
        cout << res.first << " " << res.second << '\n';
    }
}
pair<int, int> solve(VI c, int money)
{
    int n = c.size();
    map<int, int> mp;
    for (int i = 0; i < c.size(); i++)
    {
        mp[c[i]] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.count(money - c[i]) != 0 && mp[money - c[i]] != i + 1)
        {
            return {i + 1, mp[money - c[i]]};
        }
    }
    return {0, 0};
}
bool compair(pair<int, int> a1, pair<int, int> a2)
{
    if (a1.first == a2.first)
    {
        return a1.second < a2.second;
    }
    return a1.first < a2.first;
}