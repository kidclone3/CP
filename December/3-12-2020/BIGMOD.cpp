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
}

ll a, b, MOD;

ll solve(ll b)
{
    if (b == 1)
    {
        return a % MOD;
    }
    ll tmp = (solve(b / 2) % MOD);
    if (b % 2 == 0)
    {

        return (tmp * tmp) % MOD;
    }
    else
    {
        return (((tmp * tmp) % MOD) * (a % MOD)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> MOD;
    ll ans = solve(b);
    cout << ans;
}