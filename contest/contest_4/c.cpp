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
int a[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // format array a.
    F_OR(i, 0, n+1 ,1) {
        a[i] = -1;
    }
    F_OR(i, 1, m+1, 1) {
        int nn, mm;
        cin >> nn >> mm;
        if (nn==1 && mm == 0) {
            return cout<<"-1", 0;
        }
        if (a[nn]==-1) a[nn]=mm;
        else {
            if (mm!=a[nn])
                return cout<<"-1", 0;
        }
    } 
    string ans ="";
    if (a[1]==-1) ans+='1';
    else ans+=to_string(a[1]);
    // if (a[1]!=-1) ans+=to_string(a[1]);
    F_OR(i, 2, n+1, 1) {
        if (a[i]!=-1) ans+=to_string(a[i]);
        else ans+='0';
    }
    cout<<ans;
}
