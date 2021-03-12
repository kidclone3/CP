#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()

template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vi v1, v2;
    ll wsum;
    if (n * (n + 1) % 4 != 0)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        cout << "YES\n";
        wsum = n * (n + 1) / 4;
        for (ll i = n; i > 0; i--)
        {
            if (wsum >= i)
            {
                v1.pb(i);
                wsum -= i;
            }
            else
            {
                v2.pb(i);
            }
        }
        cout << v1.size() << "\n";
        print(v1);
        cout << v2.size() << "\n";
        print(v2);
    }
}