#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int a[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll count = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            count += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << count;
}