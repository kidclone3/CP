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
bool a[10000000+5];
vector<int> spawn;
void sieve(int n) {
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve(10000000);
    cout<<spawn.size();
}