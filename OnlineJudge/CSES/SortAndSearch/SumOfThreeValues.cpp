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
const int N = 5000+5;
// int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll, int>> a;
    F_OR(i, 0, n ,1) {
        ll tmp;
        cin >> tmp;
        a.pb({tmp, i+1});
    }
    sort(all(a));
    F_OR(i, 0, n ,1) {
        int l = 0, r = n-1;
        ll y = x- a[i].first;
        while(l<i && r>i) {
            ll z = a[l].first + a[r].first;
            if (z==y) {
                return cout<<a[l].second << " " << a[i].second << " " << a[r].second, 0;
            }
            if (z<y) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout<<"IMPOSSIBLE";

}