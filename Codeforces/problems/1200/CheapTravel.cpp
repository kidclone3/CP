#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
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
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll cost = 0;
    while(n>0) {
        if (n>=m && m*a > b) {
            cost += b;
            n-=m;
        }
        else {
            if (n > 0 && n < m) {
                if (n*a > b) {
                    cost += b;
                    break;
                }
            }
            cost += a;
            n--;
        }
    }
    cout << cost;
}