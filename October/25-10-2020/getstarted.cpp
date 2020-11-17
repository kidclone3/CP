#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    char a[n][n];
    if (n == 1)
    {
        cout << 'W';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            a[0][0] = 'W';
            cout << a[0][0];
        }
        else
        {
            if (a[i - 1][0] == 'W')
                a[i][0] = 'B';
            else
                a[i][0] = 'W';
            cout << a[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            if (a[i][j - 1] == 'W')
                a[i][j] = 'B';
            else
                a[i][j] = 'W';
            cout << a[i][j];
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("getstarted.inp", "r", stdin);
    freopen("getstarted.out", "w", stdout);
    int n;
    cin >> n;
    solve(n);
}