
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> a(n);
    F_OR(i, 0, n ,1) {
        cin >> a[i];
    }
    ll sum = 0LL, res = 0LL;
    int l = 0;
    F_OR(r, 0, n, 1) {
        if(a[r] <= s) res++;
        sum+=a[r];
        while(sum >= s) {
            sum-=a[l];
            l++;
        }
        if (sum <= s) res+= (ll)((r-l + 1) + 2) * (r-l) / 2; 
    }
    cout<<res;
}
