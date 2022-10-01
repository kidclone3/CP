#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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