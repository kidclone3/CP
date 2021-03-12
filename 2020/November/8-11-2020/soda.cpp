#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<pair<int, int>>
#define ll long long

int solve(VI a);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    VI a;
    for (int i = 0; i < n; i++)
    {
        int b1, b2;
        cin >> b1 >> b2;
        a.PB({b1, b2});
    }
    cout << solve(a);
}

int solve(VI a)
{
    map<int, int> mp;
    for (auto it : a)
    {
        mp[it.first]++;
        mp[it.second + 1]--;
    }
    ll tmp = 0;
    ll Max = 0;
    for (auto it : mp)
    {
        it.second += tmp;
        tmp = it.second;
        Max = max(Max, tmp);
    }

    return Max;
}