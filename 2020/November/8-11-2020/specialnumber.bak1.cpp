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
    freopen("SPECIALNUMBER1.out", "w", stdout);
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

    for (int i = 0; i < n; i++)
    {
        bool TRUE = false;
        for (int k1 = 0; k1 < i; ++k1)
        {
            if (TRUE)
                break;
            for (int k2 = 0; k2 < i; ++k2)
            {
                if (TRUE)
                    break;
                for (int k3 = 0; k3 < i; ++k3)
                {
                    if (a[k1] + a[k2] + a[k3] == a[i])
                    {
                        TRUE = true;
                        count++;
                        cout << a[i] << " " << a[k1] << " " << a[k2] << " " << a[k3] << '\n';
                        break;
                    }
                }
            }
        }
    }
    return count;
}