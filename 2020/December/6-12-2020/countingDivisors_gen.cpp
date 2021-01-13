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
        cout << it << " ";
    }
    cout << "\n";
};
// Vua thu 1 cach chia chia chia, kqua bi tle
// thu cach sang nguyen to

int a[100000+5];
int s[1000000+5];
vi prime;
void generate(int n)
{
    //Sang nguyen to;
    s[0]=s[1]=1;
    for (int i=2; i*i<=n; ++i) {
        if (s[i] == 0) {
            for (int j = i*i; j <= n; j+=i) {
                s[j] = 1;
            }
        }
    }
    for (int i=2; i<=n; ++i){
        if (s[i] == 0) {
            prime.pb(i);
        }
    }
}
ll divisors(int n)
{
    // day la ham tinh so uoc.
    // De tinh so uoc thi ta can phai phan tich thanh thua so nguyen to
    // Dung cthuc so uoc = tich (pi+1) voi pi la so mu cua cac thua so nguyen to.
    // dung sang nguyen to cho nhanh gon le
    ll res=1;
    int i=0;
    int count=0;
    
    while (n!=1)
    {
        if (n%prime[i] == 0) {
            count++;
            n/=prime[i];
        }
        else
        {
            if (count!=0) {
                res*=count+1;
            }
            count=0;
            i++;
        }
    }
    res*=count+1;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // lap 1 ham tinh so uoc cua phan tu ai
    freopen("a.out", "w", stdout);
    int n=1000003;
    
    generate(n);
    // cout<<prime.size();
    // Vi tat ca cac th deu bi tle, nen ta se tinh ra kqua truoc.
    for (int i=1; i<n; ++i) {
        cout<<divisors(i)<<", ";
    }
}