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
vector<int> dp1, dp2, dp3;
void generate() {
    for(int i = 2; i<100; ++i) {
        bool check = true;
        for(int j=2; j*j<=i; ++j) {
            if (i%j==0) {
                check = false;
                break;
            }
        }
        if (check) dp1.pb(i);
    }
    F_OR(i, 0, dp1.size()-1, 1) {
        F_OR(j, i+1, dp1.size(), 1) {
            dp2.pb(dp1[i]*dp1[j]);
        }
    }
    sort(all(dp2));
    F_OR(i, 0, dp2.size(), 1) {
        F_OR(j, i, dp2.size(), 1) {
            dp3.pb(dp2[i]+dp2[j]);
        }
    }
    sort(all(dp3));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    generate();
    // print(dp2);
    while(t--) {
        int a;
        cin >> a;
        if (binary_search(all(dp3), a)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
