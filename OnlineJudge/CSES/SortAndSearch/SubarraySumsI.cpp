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
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    F_OR(i, 0, n, 1) {
        cin>>a[i];
    }
    int l= 0;
    int res = 0;
    ll ans = 0;
    F_OR(r, 0, n, 1) {
        ans+=a[r];
        while(ans - a[l]>=k) {
            ans-=a[l];
            l++;
        }
        if (ans==k) res++;
    }
    cout<<res;
}