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

int digit(int n)  {
    int ans = 0;
    while(n>0) {
        ans++;
        n/=10;
    }
    return ans;
}
void solve() {
    int x;
    cin >> x;
    int ans = 0;
    int last = x % 10;
    F_OR(i, 1, last, 1) {
        ans += 1+2+3+4;
    }
    ans += (digit(x) + 1) * digit(x) / 2;
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}
