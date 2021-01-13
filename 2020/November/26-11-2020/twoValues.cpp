#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

vector<pair<int, int>> a;
bool cmp(pair<int, int> tmp, int key)
{
    return tmp.first < key;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back({tmp, i});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        auto tmp = lower_bound(a.begin(), a.end(), x - a[i].first, cmp);
        if (tmp->first == (x - a[i].first))
        {
            int m, M;
            m = min(a[i].second, tmp->second);
            M = max(a[i].second, tmp->second);
            if (m != M)
            {
                cout << m << " " << M;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}