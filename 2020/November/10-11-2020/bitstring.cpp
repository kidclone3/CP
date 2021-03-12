#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int divided = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ((ans % divided) * (2 % divided)) % divided;
    }
    cout << ans;
}