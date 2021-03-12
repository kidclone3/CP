#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

int a[5005];
int solve(int n, int a[]);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SPECIALNUMBER.inp", "r", stdin);
    freopen("SPECIALNUMBER2.out", "w", stdout);
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
    // If using vector, program can't run under 10s (test 9)
    set<int> vt;
    // Using map to check whether an element is loaded or not
    map<int, bool> mp;
    for (int i = 0; i < n; i++)
    {
        // If I use a function to check if elements is existed or not, my ans
        // will different.
        for (auto it : vt)
        {
            if (mp.count(a[i] - it))
            {
                count++;
                //cout << a[i] << ' ' << it << " " << mp[a[i] - it] << '\n';
                break;
            }
        }
        for (int k1 = 0; k1 <= i; ++k1)
        {
            vt.insert(a[i] + a[k1]);
        }

        if (mp[a[i]] == true)
            continue;
        else
            mp[a[i]] = false;
    }
    return count;
}