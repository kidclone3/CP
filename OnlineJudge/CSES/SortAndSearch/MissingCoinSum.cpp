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
const int N = 2*1e5+5;
ll a[N], dp[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    F_OR(i, 1, n+1, 1) {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    dp[0] = 1; //Kieu j cx phai them 1 :)
    F_OR(i, 1, n+1, 1) {
        if (dp[i-1] < a[i]) return cout<<dp[i-1], 0;
        dp[i] = dp[i-1] + a[i];
    }
    cout<<dp[n];
}
