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
        cout << it << "\n";
    }
    cout << "\n";
};
vector<ll> dp;
const ll N = 1e9+5;
void brute(ll n) {
    dp.pb(n);
    if (n>N) return;
    brute(n*10+4);
    brute(n*10+7);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("output.txt", "w", stdout);
    brute(0);
    sort(all(dp));
    dp.resize(unique(all(dp))-dp.begin());
    // print(dp);
    int n;
    cin >> n;
    cout<<lower_bound(all(dp), n) - dp.begin();
    // print(dp);

}
