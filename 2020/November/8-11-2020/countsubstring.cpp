#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

ll solve(string s);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}
ll solve(string s)
{
    ll a[s.size() + 5];
    ll k = 0;
    a[0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {

            a[i + 1] = a[i] + 1 + k;
            k++;
        }
        else
        {
            a[i + 1] = a[i];
        }
    }
    return a[s.size()];
}