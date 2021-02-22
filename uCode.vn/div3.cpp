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
ll a[100000 + 5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<ll, ll> surplus3; // số dư 3
    ll ans = 0;
    F_OR(i, 0, n, 1)
    {
        cin >> a[i];
        surplus3[a[i] % 3]++;
    }
    if (surplus3[0] > 2)
    {
        ans += surplus3[0] * (surplus3[0] - 1) / 2;
    }
    ans += surplus3[1] * surplus3[2];
    cout << ans;
}