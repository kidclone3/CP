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
int a[1000+5][1000+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >>n;
    int count = 0;
    F_OR(i, 1, n+1, 1) {
        F_OR(j, 1, n+1, 1) {
            cin >> a[i][j];
        }
    }
    F_OR(i, 1, n+1, 1) {
        F_OR(j, 1, n+1, 1) {
            vector<int> vt;
            vt.pb(a[i-1][j]);
            vt.pb(a[i+1][j]);
            vt.pb(a[i][j-1]);
            vt.pb(a[i][j+1]);
            vt.pb(a[i+1][j+1]);
            vt.pb(a[i+1][j-1]);
            vt.pb(a[i-1][j+1]);
            vt.pb(a[i-1][j-1]);
            if (a[i][j] > *max_element(vt.begin(), vt.end())) {
                count++;
            }
        }
    }
    cout << count;
}