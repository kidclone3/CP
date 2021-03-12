// https://vn.spoj.com/PTIT/problems/P136SUMC/

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
ll rev(ll a)
{
    ll tmp = 0;
    while (a > 0)
    {
        tmp *= 10;
        tmp += a % 10;
        a /= 10;
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << max(rev(a), rev(b));
}