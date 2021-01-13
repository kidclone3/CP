#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

string solve(string s)
{
    bool check = true;
    map<char, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    string res = "";
    for (auto it : mp)
    {
        if (it.second % 2 == 1)
        {
            if (check)
            {
                check = false;
                while (it.second--)
                {
                    res += it.first;
                }
            }
            else
            {
                return "NO SOLUTION";
            }
        }
    }
    for (auto it : mp)
    {
        if (it.second % 2 == 0)
        {
            string tmp(it.second / 2, it.first);
            res.insert(0, tmp);
            res.insert(res.size(), tmp);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << solve(s);
}