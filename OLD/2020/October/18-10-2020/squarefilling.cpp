#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> a, vector<vector<int>> b)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}
void solve(vector<vector<int>> a, vector<vector<int>> &b)
{
    int count = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < a[0].size() - 1; j++)
        {
            if (a[i][j] == 1)
            {
                if (a[i][j + 1] == 0 || a[i + 1][j] == 0 || a[i + 1][j + 1] == 0)
                {
                    continue;
                }
                res.push_back({i, j});
                b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
                count++;
            }
        }
    }
    if (check(a, b))
    {
        cout << count << '\n';
        for (auto it : res)
        {
            cout << it.first + 1 << " " << it.second + 1 << '\n';
        }
    }
    else
        cout << "-1";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a, b;
    a.resize(n, vector<int>(m, 0));
    b.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    solve(a, b);
}