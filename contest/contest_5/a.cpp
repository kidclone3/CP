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
ll C(int n, int k) {
    ll ans = 1; 
    ll tmp = 1;
    if (n<=1) return 0;
    // n!/(n-k)!.k!
    F_OR(i, 1, k+1, 1) {
        ans*=(n-k+i);
        tmp*=i;
    }
    return ans/tmp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll ans =0;

    ans = C(n, 2) + C(m, 2);
    cout<<ans;
}
