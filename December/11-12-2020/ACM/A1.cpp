#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
vi solve(int m)
{
    ll tmp = 0;
    vi res;
    // tmp= tong xor
    for (int i = 1; i <= m; ++i)
    {
        tmp ^= i;
    }
    // last = so bo di
    int last = 0;

    for (int x = 1; x <= m; ++x)
    {
        if (tmp ^ x == m)
        {
            last = x;
            break;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (i != last)
        {
            res.pb(i);
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    // cin >> m;
    m = 4;
    ll tmp = 0;
    vi res;
    // tmp= tong xor
    for (int i = 1; i <= m; ++i)
    {
        tmp ^= i;
    }
    // last = so bo di
    int last = 0;

    for (int x = 1; x <= m; ++x)
    {
        if ((tmp ^ x) == m)
        {
            last = x;
            break;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (i != last)
        {
            res.pb(i);
        }
    }
    cout << res.size() << "\n";
    print(res);
}