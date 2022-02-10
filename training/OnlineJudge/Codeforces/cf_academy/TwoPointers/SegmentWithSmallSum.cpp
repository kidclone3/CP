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
const int N = 1e5+5;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll s;
    cin >> n >> s;
    F_OR(i, 0, n , 1) {
        cin>>a[i];
    }
    // two pointer method.
    int res = 0, l = 0;
    ll ans = 0LL;
    F_OR(r, 0, n, 1) {
        ans+=a[r];
        // De: tim day <= S co do dai lon nhat.
        while(ans>s) {
            ans-=a[l];
            l++;
        }
        res = max(res, r-l+1);
    }
    cout<<res;
}
