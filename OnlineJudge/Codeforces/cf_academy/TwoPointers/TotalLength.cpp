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
const int N = 1e5+5;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n;
    ll s;
    cin >> n >> s;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    ll sum =0; 
    ll l = 0;
    ll res = 0;
    for(ll r = 0; r < n; ++r) {
        sum += a[r];
        while(sum>s) {
            sum -= a[l];
            l++;
        }
        if (sum<=s) {
            res += (r-l+1) * (r-l + 2) / 2;
        }
    }
    cout<<res;
}
