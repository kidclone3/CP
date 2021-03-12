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
const int N = 2005;
ll p[N][N];
ll combination(ll n, ll k) {
    // nCk %mod;
    // Tao tam giac pascal
    if (p[n][k]!=0) return p[n][k];
    if (k==0||k==n) {
        p[n][k] = 1;
        return 1;
    }
    if (k==1 || k==(n-1)) {
        p[n][k] = n;
        return n;
    }

    ll l,r;
    if (p[n-1][k]!=0) l = p[n-1][k];
    else l = combination(n-1, k);

    if (p[n-1][k-1]!=0) r = p[n-1][k-1];
    else r = combination(n-1,k-1);

    p[n][k] = (l%mod + r%mod)%mod;
    return p[n][k];
    

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int y = n-k;
    F_OR(i, 1, k+1, 1) {
        if(i>y+1) cout<<0<<"\n";
        else cout<<(combination(k-1, i-1)*combination(y+1, i))%mod <<"\n";
    }
}
