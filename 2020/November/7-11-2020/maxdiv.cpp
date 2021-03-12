#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

int a[300005];
ll solve(int n, int a[], int k);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << solve(n, a, k);
}

ll solve(int n, int a[], int k)
{
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % k)
        {
            bool check = true;
            int j = i + 1;
            while (true)
            {
                if (a[j] % k)
                {
                    j++;
                }
                else
                {
                    if (check)
                    {
                        check = false;
                        j++;
                    }
                    else
                    {
                        j--;
                        break;
                    }
                }
            }
            count += (i + j) * (j - i + 1) / 2;
            i = j + 1;
        }
        else
        {
            while (true)
            {
                if (a[])
            }
        }
        
    }
}