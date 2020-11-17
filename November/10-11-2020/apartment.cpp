#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<ll>
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vi a, b;
    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        a.pb(tmp);
    }
    for (int j = 0; j < m; j++)
    {
        ll tmp;
        cin >> tmp;
        b.pb(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i, j, count;
    i = j = count = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j] + k && a[i] >= b[j] - k)
        {
            count++;
            i++;
            j++;
        }
        else if (a[i] > b[j] + k)
        {
            j++;
        }
        else if (a[i] < b[j] - k)
        {
            i++;
        }
    }
    cout << count;
}