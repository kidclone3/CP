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
    cin >> n;
    F_OR(i, 0, n, 1) {
        F_OR(j, 0, n, 1) {
            cin>>a[i][j];
        }
    }
    ll sum = 0;
    F_OR(i, 0, n, 1) {
        F_OR(j, 0, n, 1) {
            if (j > i && j < n-1-i) {
                sum+=a[i][j];
            }
        }
        if (i == n/2) break;
    }
    cout << sum;
}