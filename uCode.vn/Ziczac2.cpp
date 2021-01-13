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
int a[1000+5], f[1000+5];
bool check(int a, int b) {
    if ((a>0 && b<0) || (a<0 && b>0)) {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int M=0;
    cin>>n; 
    F_OR(i, 0, n, 1) {
        cin>>a[i];
    }
    f[0]=1;
    F_OR(i, 1, n, 1) {
        if (check(a[i], a[i-1])) {
            f[i]=f[i-1] + 1;
        }
        else {
            f[i]= 1;
        }
        M=max(M, f[i]);
    }
    cout<<M;
}