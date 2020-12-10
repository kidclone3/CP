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

vector<pair<ll, ll>> vt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vt.pb({a, b});
    }
    sort(all(vt));
    ll t, sum;
    t = sum = 0;
    for (auto &it : vt)
    {
        t += it.first;
        sum += it.second - t;
    }
    cout << sum;
}