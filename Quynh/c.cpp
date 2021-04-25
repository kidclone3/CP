#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int d = 0, e = 0;
    if (a % 2 == 1 && b % 2 == 1)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        for (int i = 0; i < a + b; i++)
        {
            if (s[i] != '?' && s[a + b - 1 - i] != '?' && s[i] != s[a + b - 1 - i])
            {
                cout << "-1\n";
                return;
            }
            if ((a + b) % 2 == 1)
            {
                if (a % 2 == 1 && s[(a + b - 1) / 2] == '1')
                {
                    cout << "-1\n";
                    return;
                }
                if (b % 2 == 1 && s[(a + b - 1) / 2] == '0')
                {
                    cout << "-1\n";
                    return;
                }
            }
            if (s[i] == '?')
            {
                if (s[a + b - 1 - i] == '0')
                {
                    s[i] = '0';
                }
                if (s[a + b - 1 - i] == '1')
                {
                    s[i] = '1';
                }
            }
        }
        int d = 0, e = 0;
        for (int i = 0; i <= a + b - 1; i++)
        {
            if (s[i] == '0')
            {
                d++;
            }
            if (s[i] == '1')
            {
                e++;
            }
        }
        if ((a - d) % 2 == 1 && s[(a + b - 1) / 2] == '?')
        {
            s[(a + b - 1) / 2] == '0';
            a--;
        }
        if ((b - e) % 2 == 1 && s[(a + b - 1) / 2] == '?')
        {
            s[(a + b - 1) / 2] == '0';
            b--;
        }
        while ((a - d) > 0)
        {
            for (int j = 0; j <= (a + b - 1) / 2; j += 2)
            {
                if (s[j] == '?')
                {
                    s[j] = '0';
                    s[a + b - 1 - j] = '0';
                }
            }
            a-=2;
        }
        while ((b - e) > 0)
        {
            for (int j = 0; j <= (a + b - 1) / 2; j += 2)
            {
                if (s[j] == '?')
                {
                    s[j] = '1';
                    s[a + b - 1 - j] = '1';
                }
            }
            b-=2;
        }
    }
    cout << s << "\n";
}