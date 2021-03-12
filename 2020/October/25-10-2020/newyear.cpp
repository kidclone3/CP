#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> a)
{
    int sum = 0;
    vector<int> b(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        b[i] = i + 1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            if (b[i + 1] == a[i])
            {
                b.erase(b.begin() + i + 1);
                b.insert(b.begin() + i, a[i]);
                sum += 1;
            }
            else if (b[i + 2] == a[i])
            {
                b.erase(b.begin() + i + 2);
                b.insert(b.begin() + i, a[i]);
                sum += 2;
            }
            else
                return -1;
        }
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("NEWYEAR.INP", "r", stdin);
    freopen("NEWYEAR.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        int res = solve(a);
        if (res == -1)
            cout << "Too chaotic" << '\n';
        else
            cout << res << '\n';
    }
}