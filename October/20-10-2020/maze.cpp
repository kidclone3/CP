#include <bits/stdc++.h>
using namespace std;
long long solve(long long n, long long a[])
{
    if (n == 1)
        return a[0];
    long long sum = a[0];
    for (long long i = 1; i < n; i++)
    {
        if (sum % a[i] == 0)
            continue;
        else
        {
            sum = ((long long)(sum / a[i]) + 1) * a[i];
        }
    }
    return sum;
}
int main()
{
    long long n; //always need to read n first

    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << solve(n, a) << '\n';
}