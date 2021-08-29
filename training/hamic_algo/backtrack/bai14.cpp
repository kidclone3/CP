#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    IOS;
    solve();
}
void solve() {
    int n, d;
    cin >> n >> d;
    vi a(n);
    multiset<int> st;
    FOR(n) {
        cin >> a[i];
        st.insert(a[i]);
    } 
    sort(all(a));
    if (a.back() > d) {
        cout << -1;
        return;
    }
    vector<vi> ans;
    for(auto it = st.rbegin(); it != st.rend(); ++it) {
        int sum = d - *it;
        vi tmp;
        tmp.push_back(*it);
        auto next = st.upper_bound(sum);
        while (next != st.begin()) {
            next--;
            sum -= *next;
            tmp.push_back(*next);
            st.erase(next);
            next = st.upper_bound(sum);
        }
        sort(all(tmp));
        ans.push_back(tmp);
    }
    cout << ans.size() << "\n";
    EACH(it, ans) {
        print(it);
    }
}
