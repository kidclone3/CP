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
const int N = 1e5+5;
ll a[N], b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    ll n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    F_OR(i, 0, m, 1) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    int ra, rb;
    ra = n-1;
    rb = m-1;
    ll sum1, sum2;
    sum1 = sum2 = 0;
    
    cout<< sum1;

}
