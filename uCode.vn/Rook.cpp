#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
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
int a[1000 + 5][1000 + 5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    F_OR(i, 1, n + 1, 1)
    {
        F_OR(j, 1, n + 1, 1)
        {
            cin >> a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    int ans = 0;
    // Duyet nhung o cung hang, cot.
    F_OR(i, 1, n+1, 1) {
        if (i!=x) {
            ans += a[i][y];
        }
        if (i!=y) {
            ans += a[x][i];
        }
    }
    cout << ans;
}