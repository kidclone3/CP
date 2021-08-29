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
    int x, y;
    cin >> x >> y;
    int a, b;
    a = min(x, y);
    b = max(x, y);
    ll ans = 0;
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    a = ((a + 2) / 2) * 2;
    b = ((b - 1) / 2) * 2;
    ans = (b + a) * ((b - a) / 2 + 1) / 2;
    cout << ans;
}