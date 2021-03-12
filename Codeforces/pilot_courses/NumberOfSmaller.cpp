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
const int NxM = 1e5+5;
int a[NxM], b[NxM], c[NxM];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    F_OR(i, 0, m, 1) {
        cin >> b[i];
    }
    int i, j; i = j = 0;
    for(;j<m; ++j) {
        while(i<n && a[i]<b[j]) {
            i++;
        }
        c[j] = i;
    }
    c[m-1] = i;
    F_OR(i, 0, m, 1) {
        cout<<c[i] << " ";
    }
}