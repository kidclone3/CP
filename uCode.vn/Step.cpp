#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
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
    ll a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    ll l1, l2, ll1, ll2;
    l1 = x / (a+b) * (a-b);
    l2 = x / (c+d) * (c-d);
    ll1 = x % (a+b);
    ll2 = x % (c+d);
    if (ll1 <= a) {
        l1 += ll1;
    }
    else {
        l1 += 2*a - ll1;
    }
    if (ll2 <= c) {
        l2 += ll2;
    }
    else {
        l2 += 2*c - ll2;
    }
    if (l1 > l2) cout << "Ucoder";
    else if (l1 == l2) cout << "Tied";
    else cout << "Ucodi";
}
