#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> a)
{
    int n = a.size();
    sort(a.rbegin(), a.rend());
    int sum = a[0];
    int c = 1;
    if (n == 1)
        return sum;

    for (int i = 1; i < n; i++)
    {
        int tmp = sum + a[i] - c;
        if (tmp > sum)
        {
            c++;
            sum = tmp;
        }
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("easymtp.inp", "r", stdin);
    freopen("easymtp.out", "w", stdout);
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << solve(a);
}