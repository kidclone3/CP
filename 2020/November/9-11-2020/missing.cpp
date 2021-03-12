#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    VI a;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp;
        cin >> tmp;
        a.PB(tmp);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            cout << i + 1;
            break;
        }
    }
}