#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int a[2 * 100000 + 5];

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
    sort(a, a + n);
    ll cost1, cost2, ans = 0;
    int med1, med2;
    med1 = a[n / 2];
    med2 = a[n / 2 + 1];
    for (int i = 0; i < n; i++)
    {
        cost1 += abs(a[i] - med1);
        cost2 += abs(a[i] - med2);
    }
    ans = min(cost1, cost2);
    cout << ans;
}