#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define vi vector<long long int>
#define ll long long int
#define all(x) x.begin(), x.end()
#pragma GCC optimize("O3,unroll-loops")
// int n = 1;
int m, n;

vector<vector<int>> max(vector<vector<int>> &a, vector<vector<int>> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            if (a[i][j] != b[i][j])
                return a[i][j] > b[i][j] ? a : b;
        }
    }
    return a;
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] > b[0];
}

vector<vector<int>> convert(vector<vector<int>> &a)
{
    vector<vector<int>> v(a[0].size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            v[j][i] = a[i][j];
        }
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);

    cin >> m >> n;
    // vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[j][i];
        }
    }
    vector<vector<int>> ans = convert(a);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(a[j][i], a[j][0]);
        }
        sort(all(a), cmp);
        vector<vector<int>> cc = convert(a);
        sort(all(cc), greater<vector<int>>());
        ans = max(ans, cc);
        for (int j = 0; j < n; j++)
        {
            swap(a[j][i], a[j][0]);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        cout << ans[i - 1][j - 1] << endl;
    }
}