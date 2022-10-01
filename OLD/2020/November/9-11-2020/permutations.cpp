#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    else
    {
        for (int j = n - 1; j > 0; j -= 2)
        {
            cout << j << " ";
        }
        for (int j = n; j > 0; j -= 2)
        {
            cout << j << " ";
        }
    }
    return 0;
}