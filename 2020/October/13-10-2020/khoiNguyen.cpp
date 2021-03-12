#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b);

int main()
{
    string a = "daBcd";
    string b = "ABC";
    if (solve(a, b))
        cout << "YES";
    else
        cout << "NO";
}

bool solve(string a, string b)
{
    int j = 0;     // variable to access string b
    stack<int> q2; // stack to store suspects
                   // q2 for b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[j])
        {
            j++;
        }
        else if (a[i] - 32 == b[j])
        {
            q2.push(j);
            j++;
        }
        else
        {
            if (!q2.empty())
            {
                if (a[i] == b[q2.top()])
                {
                    q2.pop();
                }
                else if (isupper(a[i]))
                    return false;
            }
        }
    }
    if (j == b.size())
        return true;
    else
        return false;
}