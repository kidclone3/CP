#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

string solve(string s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << solve(s);
}
string solve(string s)
{
    for (int i = 0; i < s.size() - 1;)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 1);
        }
        else
        {
            i++;
        }
    }
    return s;
}