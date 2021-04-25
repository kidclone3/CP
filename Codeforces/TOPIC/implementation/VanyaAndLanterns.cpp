// https://codeforces.com/problemset/problem/492/B
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
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
    solve();
}
void solve() {
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    FOR(i, n) {
        cin >> a[i];
    } 
    sort(all(a));
    ll maxdist = LLONG_MIN;
    FOR(i, n-1) {
        maxdist = max(maxdist, a[i+1] - a[i]);
    }
    printf("%.10f", max((double) maxdist/2, (double) max(a[0], l-a[n-1])));
}