#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()

int f[10][10];
int ans;
int a[10]; // save the row 'th which travelled;

bool ok(int x, int y)
{
    if (f[x][y] != 0)
        return false;
    for (int i = 0; i < x; i++)
    {
        if (a[i] == y || abs(i - x) == abs(a[i] - y))
            return false;
    }
    return true;
}

void solution(int i) // i th is the row being travelled;
{
    //we are travelling by row;
    for (int j = 0; j < 8; j++)
    {
        if (ok(i, j))
        {
            f[i][j] = 2;
            a[i] = j; // luu lai vi tri.
            if (i + 1 == 8)
            {
                ans++;
                f[i][j] = 0;
                return;
            }
            solution(i + 1);
            f[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
                f[i][j] = 1;
        }
    }
    solution(0);
    cout << ans;
}