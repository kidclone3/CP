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
ll f(vector<ll> a, int b) {
    ll ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        ans += abs(a[i] - (b + (i+1)));
    }
    return ans;
}
ll terary(ll left, ll right, vector<ll> a) {
    int N_ITER = 100;
    for (int i = 1; i< N_ITER; ++i) {
        int x1 = left + (right - left + 1) / 3;
        int x2 = right - (right - left + 1) / 3;
        ll f1 = f(a, x1);
        ll f2 = f(a, x2);
        if (f1 > f2) {
            left = x1;
        }
        else if (f1 < f2){
            right = x2;
        }
        else {
            left = x1;
            right = x2;
        }
    }
    return f(a, left);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mn, mx;
    mn = LLONG_MAX;
    mx = LLONG_MIN;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    for (ll i = -mx; i<=mx; ++i) {
        cout<<f(a, i) <<"\n";
    }
    // cout<< terary(-mx, mx, a);

}
