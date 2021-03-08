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
const ll N = 5000+5;
ll a[N], b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    sort(a, a+n);
    b[0] = a[0];
    F_OR(i, 1, n, 1) {
        b[i] = b[i-1] + a[i];
    }
    ll pos = lower_bound(b, b+n, k) - b;
    if (pos ==n) {
        cout << n;
        return 0; 
    }
    // if (b[pos] == k) {
    //     cout << 0;
    //     return 0;
    // }
    int counter = 0;
    F_OR(i, 0, pos, 1) {
        if ((b[pos] - a[i]) >= k) counter ++;
        else{
            pos++;
        }
        if (pos == n) break;
    }
    cout << counter;

}