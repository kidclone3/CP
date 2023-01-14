#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    ll ans = 1 + n;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i == (n / i))
                ans += i;
            else
            {
                ans += i + n / i;
            }
        }
    }
    cout << ans;
}