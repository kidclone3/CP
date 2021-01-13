#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<vector<int>>
#define Vi vector<int>
#define ll long long

int solve(VI a);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("xeplich.inp", "r", stdin);
    //freopen("xeplich.out", "w", stdout);
    int k, n;
    VI a;
    cin >> k >> n;
    a.resize(k, vector<int>(n));

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    cout << solve(a);
}
int solve(VI a)
{
    VI f;
    f.resize(a.size(), vector<int>(a[0].size(), 0));
    f[0][0] = a[0][0];
    for (int i = 1; i < a[0].size(); i++)
    {
        f[0][i] = max(f[0][i - 1], a[0][i]);
    }
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = i; j < a[0].size(); j++)
        {
            if (j - 1 < i)
            {
                f[i][j] = f[i - 1][j - 1] + a[i][j];
            }
            else
            {
                f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[i][j]);
            }
        }
    }
    return f[a.size() - 1][a[0].size() - 1];
}
