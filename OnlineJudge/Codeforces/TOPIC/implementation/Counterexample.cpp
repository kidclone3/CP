// https://codeforces.com/problemset/problem/483/A
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
    ll l,r;
    cin >> l >> r;
    if (r-l+1 <=1) {
        cout << "-1";
        return;
    } 
    for (ll i = l; i<= r-2; i++) {
        for (ll j = i+1; j <= r-1; j++) {
            for (ll z = j+1; z <= r; z++) {
                if (__gcd(i, j) == 1 && __gcd(j, z) == 1 && __gcd(i, z) != 1) {
                    cout << i << " " << j << " " <<z;
                    return;
                }
            }
        }
    }
    cout << "-1";
}