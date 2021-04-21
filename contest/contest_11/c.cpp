
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
int side(set<int> st, int n) {
    int ans = 0;
    if (st.size() == n) {
        return 0;
    }
    if (st.size() == 1) {
        if (*st.begin() == 0 || *st.begin() == n-1) {
            return 1;
        }
        else {
            return 2;
        }
    }
    else {
        int left = 0;
        if (*st.begin() == 1) {
            ans++;
        }
        EACH(it, st) {
            if (it == left) continue;
            else {
                if (it - left > 1)
                    ans++;
                left = it;
            }
        }
        if (left!=n-1) {
            ans ++;
        }
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    int mx = 0;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        mx= max (mx, a[i]);
    }
    set<int> st[mx+1];
    F_OR(i, 0, n, 1) {
        st[a[i]].insert(i);
    }
    // EACH(it, st) {
    //     print(it);
    // }
    int ans = INT_MAX;
    EACH(it, st) {
        if (!it.empty()) {
            ans = min(ans, side(it, n));
        }
    }
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
