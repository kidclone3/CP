#include <bits/stdc++.h>
using namespace std;
string solve(vector<int> a)
{
    int n = a.size();
    int d[n];
    int left, right;
    string res = "";
    for (int i = 0; i < n; i++)
    {
        d[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            res += '1';
            left = d[i];
            right = d[i];
            continue;
        }
        left = min(left, d[i]);
        right = max(right, d[i]);
        if (right - left == i)
        {
            res += '1';
        }
        else
            res += '0';
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    //freopen("out.txt", "w", stdout);
    while (t > 0)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp - 1);
        }
        cout << solve(a) << '\n';
        t--;
    }
}