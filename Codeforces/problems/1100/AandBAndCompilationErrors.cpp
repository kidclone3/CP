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
    solve();
}
void solve() {
    int n;
    cin >> n;
    multiset<int> st1, st2;
    FOR(i, n) {
        int tmp;
        cin >> tmp;
        st1.insert(tmp);
    } 
    FOR(i, n-1) {
        int tmp;
        cin >> tmp;
        st2.insert(tmp);
        auto it = st1.lower_bound(tmp);
        st1.erase(it);
    } 
    print(st1);
    FOR(i, n-2) {
        int tmp;
        cin >> tmp;
        auto it = st2.lower_bound(tmp);
        st2.erase(it);
    } 
    print(st2);
}