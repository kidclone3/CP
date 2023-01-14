#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--) solve();
}
void solve() {
    ll p, q;
    cin >> p >> q;
    if (p % q != 0) {
        cout << p << "\n";
        return;
    }
    ll q2 = q;
    vector<pair<ll, ll>> uoc;
    for (ll i = 2; i*i <= q2; ++i) {
        if (q2 % i == 0) {
            ll cnt = 0;
            while(q2 % i == 0) {
                q2/=i;
                cnt++;
            }
            uoc.push_back({i, cnt});
        }
    }
    if (q2 > 1) uoc.push_back({q2, 1});
    q2 = q;
    ll mn = 1e18;
    EACH(it, uoc) {
        // p = it^a1 * K
        // q = it^a2 * G
        // a1 >= a2 => Neu X = it^(a2-1) * K => ko chia het cho q.
        // => p can chia 1 so it^(a1 - a2 + 1), va no la nho nhat.
        ll p2 = p;
        ll a1 = 0;
        while(p2 % it.first == 0) {
            p2 /= it.first;
            a1 ++;
        }
        // a2 = it.second
        ll tmp = 1;
        FOR(i, a1-it.second + 1) {
            tmp *= it.first;
        }
        
        mn = min(mn, tmp);
    }
    if ((p / mn) % q != 0) {
        cout << p/mn << "\n";
    }
    else {
        while(p % q == 0) p/= q;
        cout << p <<"\n";
    }
}