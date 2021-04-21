// https://codeforces.com/contest/1514/problem/C
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
const int N = 1e5+5;
bool ok[N];
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    int n;
    cin >> n;
    ll product = 1;
    vector<int> ans;
    FOR1(i, n-1) {
        if (__gcd(n, i) == 1) {
            ok[i] = 1;
            product = (product*i) % n;
        }
    }
    if (product != 1) {
        ok[product] = 0;
    }
    cout << count(ok+1, ok+n+1, 1) <<"\n";
    FOR1(i, n) {
        if (ok[i]) cout << i <<" ";
    }
}