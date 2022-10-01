#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<int, int> a, pair<int, int> b)

{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main()
{
    vector<pair<int, int>> vt = {{3, 1}, {4, 2}, {1, 3}, {3, 4}, {6, 5}, {2, 6}, {7, 7}, {3, 8}, {3, 9}};
    sort(vt.begin(), vt.end());
    for (auto &it : vt)
        cout << "{ " << it.first << ", " << it.second << "}";
    cout << "\n";
    pair<int, int> it;

    auto i = lower_bound(vt.begin(), vt.end(), make_pair(3, -10));
    cout << i->first << " " << i->second;
}