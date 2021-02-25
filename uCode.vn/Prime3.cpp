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
const int N = 10000000+5;
bool a[N];
vector<int> spawn;
void sieve() {
    int n = N;
    if (n < 2) return;
    a[0] = a[1] = 0;
    for (int i=2; i*i < n; ++i) {
        if (a[i] == 0) {
            for (int j = i*2; j <= n; j += i) {
                a[j] = 1;
            }
        }
    }
    for (int i=2; i<=n; ++i) {
        if (a[i] == 0) {
            spawn.pb(i);
        }
    }
}
bool solve(ll n) {
    sieve();
    EACH(it, spawn) {
        if (n == it) return true;
        if (n % it == 0 || it > n) {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    solve(n) ? (cout<<"yes") : (cout<<"no");
}