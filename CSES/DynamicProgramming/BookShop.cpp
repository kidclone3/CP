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
const int N = 1e3+5;
int a[N], b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    F_OR(i, 0, n ,1) {
        cin >> a[i];
    }
    F_OR(i, 0, n ,1) {
        cin >> b[i];
    }
    vector<pair<int, ll>> vt(n);
    vector<ll> f(x+1, 0);
    bitset<N> bt[x+1];
    F_OR(i, 0, n ,1) {
        vt[i] = {a[i], b[i]};
    }
    ll mx = 0; // max
    sort(all(vt));
    F_OR(i, 0, n, 1) {
        F_OR(j, x, a[i]-1, -1) {
            
        }
    }
    cout<<mx;
}
