#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 != 0 || abs(a - b) > min(a, b))
        {
            cout << "NO\n";
        }
        else
            cout << "YES\n";
    }
}