#include <bits/stdc++.h>
using namespace std;
int solve(string s[3])
{
    sort(s, s + 3);
    int s1, s2, s3;
    s1 = s[0][0];
    s2 = s[1][0];
    s3 = s[2][0];
    if (s[0][1] == s[1][1] && s[1][1] == s[2][1])
    {
        if (s1 == s2 && s2 == s3)
        {
            return 0;
        }
        if (s1 + 1 == s2 && s2 + 1 == s3)
        {
            return 0;
        }
        if (s1 == s2 || s2 == s3)
            return 1;
        if (s1 + 1 == s2 || s2 + 1 == s3 || s1 + 1 == s3)
        {
            return 1;
        }
        if (s1 + 2 == s2 || s2 + 2 == s3 || s1 + 2 == s3)
            return 1;
        return 2;
    }
    if (s[0][1] == s[1][1])
    {
        if (s1 == s2)
            return 1;
        if (s2 - s1 <= 2)
            return 1;
    }
    if (s[1][1] == s[2][1])
    {
        if (s2 == s3)
            return 1;
        if (s3 - s2 <= 2)
            return 1;
    }
    if (s[0][1] == s[2][1])
    {
        if (s1 == s3)
            return 1;
        if (s3 - s1 <= 2)
            return 1;
    }
    return 2;
}
int main()
{
    string s[3];
    for (int i = 0; i < 3; ++i)
    {
        cin >> s[i];
    }
    cout << solve(s);
}