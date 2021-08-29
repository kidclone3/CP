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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >>n;
        vi a(n);
        F_OR(i, 0, n, 1) {
            cin >> a[i];
        }
        ll res = 0;
        sort(all(a));
        ll l = 0;
        ll r = 2;
        for (; l<n-2; ++l) {
            // if (r<n-1) r++;
            // int r= n-1;
            while (r+1 < n && a[r+1] - a[l] <= 2 ) {
                // res+=r-l-1;
                r++;
            }
            if ((r-l) >=2 && a[r] - a[l] <=2) {
                res+= (r-l-1)*(r-l)/2;
            }
        } 
        cout<<res<<"\n";
    }
}
