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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, nums = 0;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        auto it = upper_bound(all(a), tmp);
        if (it == a.end())
        {
            a.pb(tmp);
        }
        else
        {
            a[it - a.begin()] = tmp;
        }
    }
    cout << a.size();
}