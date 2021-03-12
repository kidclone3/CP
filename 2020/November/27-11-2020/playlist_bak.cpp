#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

const int N = 2 * 100000 + 5;
ll a[N], f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll M = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i]] == 0)
        {
            f[i] = f[i - 1] + 1;
            mp[a[i]] = i;
            M = max(f[i], M);
        }
        else
        {
            f[i] = i - mp[a[i]];
            mp[a[i]] = i;
            M = max(f[i], M);
        }
    }
    cout << M;
}