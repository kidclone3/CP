#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>

int a[5005];

int solve(int n, int a[]);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SPECIALNUMBER.inp", "r", stdin);
    freopen("SPECIALNUMBER.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(n, a);
}

int solve(int n, int a[])
{
    int count = 0;

    vector<int> vt;
    // map de danh dau phan tu
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {

        if (mp[a[i]] == true)
        {
            count++;
            cout << a[i] << '\n';
            continue;
        }
        for (int k = 0; k < i; k++)
        {
            vt.pb(a[i] + a[k]);
        }
        for (auto it : vt)
        {
            if (mp.find(a[i] - it) != mp.end())
            {
                mp[a[i]] = true;
                cout << a[i] << '\n';
                count++;
                break;
            }
        }
        vt.pb(a[i] * 2);
        //cout << vt.size() << '\n';
    }

    return count;
}