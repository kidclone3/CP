#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> t1, pair<int, int> t2)
{
    return t1.second < t2.second;
}
void solve(vector<pair<int, int>> a)
{
    map<int, int> mp;
    for (auto it : a)
    {
        switch (it.first)
        {
        case 1:
        {
            mp[it.second]++;
            break;
        }
        case 2:
        {
            if (mp.count(it.second))
            {
                if (mp[it.second] > 0)
                    mp[it.second]--;
            }
            break;
        case 3:
        {
            bool ok = true;
            for (auto j : mp)
            {
                if (j.second == it.second)
                {
                    cout << 1 << '\n';
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << 0 << '\n';
            }
        }
        }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("frequency.inp", "r", stdin);
    freopen("frequency.out", "w", stdout);
    int n;
    vector<pair<int, int>> inp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        inp.push_back({a, b});
    }
    solve(inp);
}