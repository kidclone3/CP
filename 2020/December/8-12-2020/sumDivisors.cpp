#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it.first << " " <<it.second<<"\n";
    }
    cout << "\n";
};

ll MOD= 1000000007;
// Can 1 ham de phan tich thua so nguyen to.
// Ta co thuat toan log(n).
ll sum(ll n)
{
    vector<pair<int, int>> p;
    int count=0;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                count++;
                n/=i;
            }
            p.pb({i, count});
            count=0;
        }
    }
    if (n>1)
    {
        p.pb({n, 1});
    }
    ll ans=1;
    for(auto &it:p)
    {
        ans*=( (ll) pow(it.first, it.second+1) - 1) / (it.first-1);
    }
    return ans;
}
ll solve(ll n)
{
    ll ans=0;
    for(int i=1; i<=n; ++i) {
        (ans+=sum(i)%MOD) % MOD;
    }
    return ans;
}
// Dua tren cong thuc Tong cac uoc so = tich (pi^(ai+1)-1)/(pi-1)
// Tich cua 1 + pi +... + p^ai = (p^(ai+1)-1)/(pi-1);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<solve(n);
}