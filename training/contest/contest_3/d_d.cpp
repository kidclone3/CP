// Blue and Red balls;
// Y' tuong: Dung to hop, chinh hop.
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
const ll mod = 1e9+7;
ll solve(int n, int k) {
    // nCk %mod;
    // cthuc: n!/[(n-k)!.k!] = (n-k+1). ... (n) / (1.2.3...k)
    // ll ans = 0;
    // if (n==k || k==0) return 1;
    // if (k==1|| k==n-1) return n%mod;
    // return (solve(n-1, k)%mod + solve(n-1, k-1)%mod)%mod; 
    ll ans = 1;
    for(int i = 1; i<=k; ++i) {
        (ans*=((n-k+i)/i)%mod)%=mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int kk = k - 1;
    ll store = 0;
    ll nn = n-k-1;
    cout<<(n-k+1)<<"\n";
    F_OR(i, 2, k, 1) {
        ll kkk = solve(kk, i-1);
        // Dung cthuc nCk, nhung la voi mod
        cout<<solve(nn, kkk)<<'\n';
    }
    cout<<solve(nn+2, k);
}