#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int a[2 * 100000 + 5], b[2 * 100000 + 5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, M = 0, tmp = -1;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        mp[a[i]]++;
        mp[b[i] + 1]--;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (tmp == -1)
        {
            M = max(M, i->second);
            tmp = i->second;
            continue;
        }
        else
        {
            i->second += tmp;
            M = max(M, i->second);
            tmp = i->second;
        }
    }
    cout << M;
}