#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, int a[]);
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << solve(n, k, a) << '\n';
    return 0;
}
int solve(int n, int k, int a[])
{
    int count = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i] + k] != 0)
        {
            count++;
        }
    }
    return count;
}
