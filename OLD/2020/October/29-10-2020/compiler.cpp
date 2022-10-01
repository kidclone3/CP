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
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}

int solve(string s)
{
    int M, sum, remaining;
    M = remaining = 0;
    //Vecto de luu dau <. voi moi dau <, vecto se them vao no so 0. 
    //Neu gap > thi 
    vector<int> vt;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            vt.push_back(0);
        }
        else
        {
            if (!vt.empty() && vt.back() == 0)
            {
                vt.back() = 1;
            }
            else
            {
                int s = 1;
                while (!vt.empty() && vt.back() != 0)
                {
                    s += vt.back();
                    vt.pop_back();
                }
                if (!vt.empty())
                {
                    vt.back() = s;
                }
                else
                {
                    if (s - 1 != 0)
                        vt.push_back(s - 1);
                }
            }
        }
    }
    if (vt.empty())
        return 0;
    if (vt.size() == 1)
        return vt[0] * 2;
    else
    {
        sort(vt.begin(), vt.end());
        return vt.back() * 2;
    }
}
