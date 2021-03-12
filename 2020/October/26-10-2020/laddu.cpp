#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

int month(string s, vector<pair<string, int>> vt);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        vector<pair<string, int>> vt;
        int acti, s2;
        string s, s1;
        cin >> acti >> s;
        for (int i = 0; i < acti; i++)
        {
            cin >> s1;
            if (s1 == "TOP_CONTRIBUTOR" || s1 == "CONTEST_HOSTED")
            {
                s2 = 0;
            }
            else
            {
                cin >> s2;
            }
            vt.push_back({s1, s2});
        }
        cout << month(s, vt) << '\n';
    }
}
int month(string s, vector<pair<string, int>> vt)
{
    int avg, sum = 0;
    avg = (s == "INDIAN") ? 200 : 400;

    for (auto it : vt)
    {
        if (it.first == "CONTEST_WON")
        {
            if (it.second > 20)
            {
                sum += 300;
            }
            else
            {
                sum += 300 + 20 - it.second;
            }
        }
        if (it.first == "TOP_CONTRIBUTOR")
        {
            sum += 300;
        }
        if (it.first == "BUG_FOUND")
        {
            sum += it.second;
        }
        if (it.first == "CONTEST_HOSTED")
        {
            sum += 50;
        }
    }
    return sum / avg;
}