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
ll a[100000+5];
ll solve (ll *a, int n) {
    if (a[0] < 0) {
        if (a[n-1] < 0)
        {
            return a[n-1] * a[n-2];
        }
        else {
            return a[0] * a[n-1];
        }
    }
    else {
        return a[0] * a[1];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    sort(a, a+n);
    cout << solve (a, n);
}
