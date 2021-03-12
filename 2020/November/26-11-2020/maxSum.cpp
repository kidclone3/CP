// Maximum subarray sum cses.fi sort and search.

#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100000 + 5;
long long a[N], f[N];
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long M;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //Kadane's algorithm

    f[0] = a[0];
    M = f[0];
    for (int i = 1; i < n; i++)
    {
        f[i] = max(a[i], f[i - 1] + a[i]);
        M = max(M, f[i]);
    }
    cout << M;
}