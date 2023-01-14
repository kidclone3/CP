#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        char a[n][n];
        int b[4];
        int p = 0, q = 1;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> a[j][k];
                if (a[j][k] == '*')
                {
                    b[p] = j;
                    b[q] = k;
                    p += 2;
                    q += 2;
                }
            }
        }
        if (b[0] != b[2] && b[1] != b[3])
        {
            a[b[0]][b[3]] = '*';
            a[b[2]][b[1]] = '*';
        }
        else if (b[0] == b[2])
        {
            if (b[0] == 0)
            {
                a[1][b[1]] = '*';
                a[1][b[3]] = '*';
            }
            else
            {
                a[0][b[1]] = '*';
                a[0][b[3]] = '*';
            }
        }
        else
        {
            if (b[1] == 0)n
            {
                a[b[0]][1] = '*';
                a[b[2]][1] = '*';
            }
            else
            {
                a[b[0]][0] = '*';
                a[b[2]][0] = '*';
            }
        }
        for (int r = 0; r < n; r++)
        {
            for (int s = 0; s < n; s++)
            {
                cout << a[r][s];
            }
            cout<<"\n";
        }
    }

}