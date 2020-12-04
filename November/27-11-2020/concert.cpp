#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

const int N = 2 * 100000 + 5;
ll a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<ll, int> mp;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        auto it = mp.lower_bound(b[i]);
        if (it->first == b[i])
        {
            cout << b[i] << "\n";
            it->second--;
            if (it->second == 0)
            {
                if (mp.size() > 0)
                {
                    mp.erase(it);
                }
                else
                {
                    mp.clear();
                }
            }
        }
        else
        {
            if (it == mp.begin())
                cout << "-1\n";
            else
            {
                it--;
                cout << it->first << "\n";
                it->second--;
                if (it->second == 0)
                {
                    if (mp.size() > 0)
                    {
                        mp.erase(it);
                    }
                    else
                    {
                        mp.clear();
                    }
                }
            }
        }
    }
}