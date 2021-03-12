#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

int solve(string s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}
int solve(string s)
{
    int n = s.size() / 2;
    int a, b, c1, c2;
    a = b = c1 = c2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            c1++;
            if (s[i] - '0')
                a++;
        }
        else
        {
            c2++;
            if (s[i] - '0')
            {
                b++;
            }
        }
        if ((n - c2 + b < a) || (n - c1 + a < b))
            return i + 1;
    }
    return s.size();
}