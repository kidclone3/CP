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
bool dense(double mx, double mn) {
    return (mx*1.0/mn) <=2.0;
}
int solve(vector<int> a) {
    int res = 0;
    F_OR(i, 1, a.size(), 1) {
        int mn = min(a[i], a[i-1]);
        int mx = max(a[i], a[i-1]);
        
        while(mx>mn && !dense(mx, mn)) {
            if (mx&1){
                mx = mx/2+ 1;
            }
            else {
                mx = mx/2;
            }
            res++;
        }    
        
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        F_OR(i, 0, n, 1) {
            cin>>a[i];
        }
        cout<<solve(a) <<"\n";
    }
}
