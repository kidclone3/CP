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
int a, b;
int k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> k;
    ll ans = 0;
    for (int i = sqrt(a) - 1; i*i <= b; ++i) {
        for (int j = pow(a, 0.3333333333) - 1; j*j*j <= b; ++j) {
            if (i*i >= a && j*j*j >=a) {
            if (abs(i*i - j*j*j) <= k)
            {
                ans ++;
            }
            }
        }
    }
    cout<<ans;
}