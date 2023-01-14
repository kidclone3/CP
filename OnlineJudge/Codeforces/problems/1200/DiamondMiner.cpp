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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        int a0, b0;
        a0 = b0 = 0;
        F_OR(i, 0, 2*n, 1) {
            ll l, r;
            cin >> l >> r;
            if (l==0) {
                b[b0++] = abs(r);
            }
            else {
                a[a0++] = abs(l);
            }
        }
        sort(all(a));
        sort(all(b));
        double ans = 0;
        F_OR(i, 0, n, 1) {
            ans += sqrt(a[i]*a[i] + b[i]*b[i]);
        }
        cout<<setprecision(17)<<ans<<'\n';
    }
}
