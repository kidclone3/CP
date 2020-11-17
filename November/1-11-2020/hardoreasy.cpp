#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long
ll solve(int n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n / 5;
        n /= 5;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("hardoreasy.inp", "r", stdin);
    //freopen("hardoreasy.out", "w", stdout);
    int n;
    cin >> n;
    cout << solve(n);
}