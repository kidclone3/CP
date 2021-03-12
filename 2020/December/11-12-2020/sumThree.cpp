#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<ll>
#define ll long long
#define all(x) (x).begin(), (x).end()
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
int n;
ll x;
ll a[5000 + 5];
void solve()
{
    cin >> n >> x;
    // Y tuong: tinh tong cua 2 phan tu bat ki (vi tri khac biet)
    // => luu vao 1 mang => space O(tong 1->n) (max ~12500000)
    // tinh dau tien la phan tu dan dau ==> 0
    // tinh thu 2 la a1; => co a1.a2
    // Co nen luu thanh pair? ==> no, luu vao tuple roi dung set de sort.
    set<tuple<ll, int, int>> st;
    set<ll> out;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i > 1)
        {
            for (int j = 1; j < i; ++j)
            {
                st.insert({a[i] + a[j], j, i});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        bool filled = false;
        auto it = st.lower_bound({x - a[i], -1, -1});

        ll f = get<0>(*it);
        while (f == x - a[i])
        {
            f = get<0>(*it);
            ll s = get<1>(*it);
            ll t = get<2>(*it);
            // cout << f << " " << s << " " << t << " " << i << " " << '\n';
            if (f == x - a[i] && i != s && i != t)
            {
                out.insert(s);
                out.insert(t);
                out.insert(i);
                filled;
                filled = true;
                break;
            }
            ++it;
        }
        if (filled) break;
    }
    if (out.size() < 3)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    else
    {
        print(out);
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}