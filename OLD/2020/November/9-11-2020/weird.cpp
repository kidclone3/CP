#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while (n > 1)
    {
        cout << n << ' ';
        if (n % 2 == 0)
            n /= 2;
        else
        {
            n = n * 3 + 1;
        }
    }
    cout << n;
}