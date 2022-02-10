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
ll w[N], c[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    ll n, s;
    cin >> n >> s;
    F_OR(i, 0, n, 1) {
        cin >> w[i];
    }
    F_OR(i, 0, n, 1) {
        cin >> c[i];
    }
    ll c_max;
    c_max = LLONG_MIN;
    ll sum_w, sum_c;
    sum_w = sum_c = 0;
    ll l = 0;
    for (ll r = 0; r <n; ++r) {
        sum_w += w[r];
        sum_c += c[r];
        while(sum_w > s) {
            sum_w -= w[l];
            sum_c -= c[l];
            l++;
        }
        c_max = max(c_max, sum_c);
    }
    cout<< c_max;
}
