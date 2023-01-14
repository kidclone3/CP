#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
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
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
ll n, m, c;
int ope;
ll a[200];
int check[200];
ll solve(){
    memset(check, 0, sizeof check);
    ll sum = 0LL;
    ll mx = 0LL;
    FOR(n) {
        cin >> a[i];
    }
    bool succeed = true;
    FOR(m) {
        cin >> ope;
        ope--;
        if (!check[ope]) {
            sum += a[ope];
            mx = max(mx, sum);
            if (sum > c) {
                succeed = false;
            }
            check[ope] = 1;
        }
        else {
            sum -= a[ope];
            check[ope] = 0;
        }
        // check[ope] = 1-check[ope];
    }
    return succeed ? mx : -1;
}

int main()
{
    IOS;
    int seq = 1;
    while(true) {
        cin >> n >> m >> c;
        if (n == m && m == c && n == 0) break;
        // if (seq > 1) cout << "\n";
        cout << "Sequence " << seq << "\n";
        seq++;
        ll ans = solve();
        if (ans == -1) {
            cout << "Fuse was blown.\n\n";
        }
        else {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << ans <<" amperes.\n\n";
        }
    }
    return 0;
}