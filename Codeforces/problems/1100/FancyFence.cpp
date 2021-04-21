#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
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
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n;
    cin >> n;
    // cthuc: goc = (1- 2/so_dinh) * 180
    double so_dinh = 2/(1-n*1.0/180.0);
    int so_dinh_nguyen = round(so_dinh);
    (so_dinh_nguyen >= 3 && abs(so_dinh_nguyen - so_dinh) < 1e-6) ? (cout << "YES\n") : (cout << "NO\n");
    
}