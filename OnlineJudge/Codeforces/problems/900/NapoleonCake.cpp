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
        vector<int> a(n+2, 0), b(n+2, 0);
        F_OR(i, 1, n+1, 1) {
            cin >> a[i];
        }
        int tmp = 0;
        F_OR(i, n, 0, -1) {
            tmp = max(tmp, a[i]);
            if (tmp) {
                tmp--;
                b[i] = 1;
            }
        }
        F_OR(i, 1, n+1, 1) {
            cout<<b[i] << " ";
        }
        cout<<'\n';
    }
}
