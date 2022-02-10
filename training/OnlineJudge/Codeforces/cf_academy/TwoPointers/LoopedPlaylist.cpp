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
const int N = 1e3 + 5;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n;
    ll p;
    cin >> n >> p;
    ll sum = 0;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        sum+=a[i];
    }
    ll pp = p/sum;
    p %= sum;
    int l = 0;
    int l_min, length;
    l_min = INT_MAX;
    length = INT_MAX;
    ll sum2 = 0;
    F_OR(r, 0, 2*n, 1) {
        sum2+=a[r%n];
        while(sum2 - (ll) a[l%n] >= p) {
            sum2-= (ll) a[l%n];
            l++;
        }
        if (sum2>=p) {
            if (length > r-l+1) {
                l_min = l%n;
                length = r-l+1;
            }
        }
    }
    cout<<l_min + 1 << " " << length + pp*n;
    

}
