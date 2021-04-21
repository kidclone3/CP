#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<long long>
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (long long i=(a); (step)>0? i<(b) : i>(b); i+=(step))
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
void solve(vector<pair<long long, long long>> base, long long a, long long b) {
    long long n = base.size();
    F_OR(i, 0, n-1, 1) {
        long long turn = (base[i].second -1) / a + 1;
        if (turn * base[i].first > b) {
            cout<<"NO\n";
            return;
        }
        else {
            b -= turn*base[i].first;
            if (b < 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    long long turn = (base[n-1].second - 1) / a + 1;
    b -= (turn - 1) * base[n-1].first;
    if (b<1) {
        cout<<"NO\n";
        return;
    }
    base[n-1].second -= (turn - 1) * a;
    if (a>=base[n-1].second) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    long long t;
    cin >> t;
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        vi x(n), y(n);
        vector<pair<long long, long long>> base(n);
        F_OR(i, 0, n, 1) {
            cin >> x[i];            
        }
        F_OR(i, 0, n, 1) {
            cin >> y[i];            
            base[i] = {x[i], y[i]};
        }
        sort(all(base));
        solve(base, a, b);
    }
}
