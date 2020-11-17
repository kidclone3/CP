#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cardgame.inp", "w", stdout);
    int n = 100;
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int a, b;
        a = (int)rand() % 2;
        if (a == 1)
        {
            cout << "A ";
            b = (ll)rand() + 1;
            cout << b << '\n';
        }
        else
            cout << "P\n";
    }
}