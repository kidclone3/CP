// https://codeforces.com/problemset/problem/727/A
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<ll>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (ll i = 0; i < (a); ++i) 
#define FOR1(i, a) for (ll i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (ll i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (ll i=(a); (step)>0? i<(b) : i>(b); i+=(step))
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

vector<ll> ans; 
void print() {
    cout << "YES\n";
    cout << ans.size() <<'\n';
    EACH(it, ans) {
        cout << it << " ";
    }
}
bool found = false;
void recursion (ll n, ll b) {
    if (n > b || found) return;
    else {
        if (n==b) {
            found = true;
            print();
        }
        else {
            ans.pb(2*n);
            recursion(2 * n, b);
            ans.pop_back();
            ans.push_back(10*n+1);
            recursion(10*n+1, b);
            ans.pop_back();
        }
    }
}
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    ll a, b;
    cin >> a >> b;
    ans.pb(a);
    recursion(a,b);
    if (!found) {
        cout << "NO";
    }
}