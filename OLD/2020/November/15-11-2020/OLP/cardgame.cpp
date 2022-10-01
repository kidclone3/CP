#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<pair<char, ll>>
#define ll long long

void solve(vi vt)
{
    priority_queue<ll> p_q;
    for (auto it : vt)
    {
        if (it.first == 'A')
        {
            p_q.push(it.second);
        }
        else
        {
            if (p_q.empty())
            {
                cout << "-1\n";
                continue;
            }
            int M = p_q.top();
            int count = 1;
            p_q.pop();
            while (!p_q.empty() && p_q.top() == M)
            {
                count++;
                p_q.pop();
            }
            cout << count << "\n";
        }
    }
    if (p_q.empty())
    {
        cout << "-1";
        return;
    }
    while (!p_q.empty())
    {
        cout << p_q.top() << ' ';
        p_q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cardgame.inp", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    ll n;
    cin >> n;
    vi vt;
    for (ll i = 0; i < n; i++)
    {
        char a;
        ll b;
        cin >> a;
        if (a == 'A')
            cin >> b;
        else
            b = 0;
        vt.pb({a, b});
    }
    solve(vt);
}