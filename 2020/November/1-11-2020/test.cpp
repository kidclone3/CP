#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("icecream.inp", "w", stdout);
    cout << "50" << '\n';
    for (int i = 0; i < 50; i++)
    {
        cout << rand() % 10000 << '\n';
        int n = rand() % 10000;
        cout << n << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << rand() % 10000 << " ";
        }
    }
}