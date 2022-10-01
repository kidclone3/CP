#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

void solve(ll m);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("onlythree.inp", "r", stdin);
    //freopen("onlythree.out", "w", stdout);
    ll m;
    cin >> m;
    solve(m);
}

void solve(ll m)
{
    vector<ll> l, r;
    ll c = 0;
    while (m > 0)
    {
        int tmp = m % 3;
        if (tmp == 2)
        {
            l.pb(c);
            c++;
            m++;
            m /= 3;
            tmp = m % 3;
        }
        if (tmp == 1)
        {
            r.pb(c);
            c++;
            m--;
            m /= 3;
            tmp = m % 3;
        }
        if (tmp == 0)
        {
            c++;
            m /= 3;
        }
    }
    if (l.empty())
    {
        cout << "-1\n";
    }
    else
    {
        for (auto it : l)
        {
            cout << it << " ";
        }
        cout << '\n';
    }
    if (r.empty())
    {
        cout << "-1";
    }
    else
    {
        for (auto it : r)
        {
            cout << it << " ";
        }
    }
}
