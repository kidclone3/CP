
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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        int j = n-1;
        int ii = 0;
        F_OR(i, 0, n, 1) {
            cin >> a[i];
        }
        F_OR(i, 0, n, 1) {
            if (i&1) {
                b[i] = a[j--];
            }
            else {
                b[i] = a[ii++];
            }
        }
        F_OR(i, 0, n, 1) {
            cout<<b[i] <<" ";
        }
        cout<<'\n';
    }
}
