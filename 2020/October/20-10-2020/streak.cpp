#include <bits/stdc++.h>
using namespace std;
int solve(vector<string> a, string s)
{
    int count = 0;
    int M = 0; //max;
    for (int i = 0; i < a.size();)
    {
        if (a[i] == s)
        {
            i++;
            count++;
            while (a[i] == s)
            {
                i++;
                count++;
            }
            M = max(M, count);
            count = 0;
        }
        else
            i++;
    }
    M = max(M, count);
    return M;
}
int main()
{
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << solve(a, "Heads") << " " << solve(a, "Tails");
}