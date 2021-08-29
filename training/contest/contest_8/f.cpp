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
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n), b(n);
        F_OR(i, 0, n, 1) {
            int l, r;
            cin >> l >> r;
            a[i] = {l, r};
            b[i] = {r, l};
        }
        sort(all(a));// sort theo l
        sort(all(b));// sort theo r
        vi c(n), d(n);
        F_OR(i, 0, n, 1) {
            c[i] = a[i].first;// c= sort theo left
            d[i] = b[i].first;// d= sort theo right
        }
        int res = INT_MAX;
        F_OR(i, 0, n, 1) {
            // a = {l, r}
            // l => lb -1 cua b
            int l, r;
            l = a[i].first;
            r = a[i].second;
            auto ia = lower_bound(all(d), l);
            auto ib = upper_bound(all(c), r);
            if (ia == d.begin()) {
                if (ib==c.end()) {
                    res = 0;
                    break;
                }
                else {
                    int tmp = c.end() - ib;
                    res = min(res, tmp);
                }
            }
            else {
                ia--;
                if (ib==c.end()) {
                    int tmp = ia-d.begin() + 1;
                    res = min(res, tmp);
                }
                else {
                    int tmp = ia-d.begin() + 1;
                    tmp += c.end() - ib;
                    res = min(res, tmp);
                }
            }
        }
        cout<<res<<'\n';
    }
}
