#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
    int n = s.size();
    int mid = n / 2;
    bool odd;
    (n % 2) ? (odd = true) : (odd = false);
    string s1, s2;
    if (odd)
    {
        s1 = s.substr(0, mid);
        s2 = s.substr(mid + 1, mid);
    }
    else
    {

        s1 = s.substr(0, mid);
        s2 = s.substr(mid, mid);
    }
    map<char, int> m1, m2;
    for (int i = 0; i < s1.size(); ++i)
    {
        m1[s1[i]]++;
        m2[s2[i]]++;
    }
    for (auto i : m1)
    {
        if (i.second != m2[i.first])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string tmp;
        cin >> tmp;
        check(tmp) ? (cout << "YES" << '\n') : (cout << "NO" << '\n');
    }
}