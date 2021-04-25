#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i)
#define FOR1(i, a) for (int i = 1; i < (a + 1); ++i)
#define F0R(i, a, b) for (int i = (a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
ll solve(ll n);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    ll l, r;
    while (cin >> l >> r)
    {
        ll a = min(l, r);
        ll b = max(l, r);
        ll mx, mxx;
        mx = LLONG_MIN;
        F_OR(i, a, b+1, 1)
        {
            ll tmp = solve(i);
            if (tmp > mx)
            {
                mx = tmp;
                mxx = i;
            }
        }
        cout << l << " " << r <<" "<<  mx << "\n";
    }
}
ll solve(ll n)
{
    ll ans = 0;
    while (n > 1)
    {
        if (n & 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n /= 2;
        }
        ans++;
    }
    ans++;
    return ans;
}