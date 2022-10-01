#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define VI vector<int>
#define ll long long

ll solve(VI vto);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, tmp;
        VI inp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            inp.PB(tmp);
        }
        cout << solve(inp) << '\n';
    }
}

ll solve(VI v)
{
    // stack dang LIFO, pair<vi tri, gia tri>
    stack<pair<int, int>> mystack;
    mystack.push({0, v[0]});
    if (v.size() == 1)
        return v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < mystack.top().second)
        {
            mystack.push({i, v[i]});
        }
    }
    int last_index = mystack.size();
    int last_value = 0;
    ll res = 0;
    while (!mystack.empty())
    {
        res += last_index * (mystack.top().second - last_value);
        last_index = mystack.top().first + 1;
        last_value = mystack.top().second;
        mystack.pop();
    }
    return res;
}