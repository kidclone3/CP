#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << 0 << "\n";
    if (n == 1)
        return 0;
    for (int i = 2; i < n + 1; i++)
    {
        ll a1 = i * i;
        ll ans = a1 * (a1 - 1) / 2 - (i - 1) * (i - 2) * 4;
        cout << ans << "\n";
    }
}