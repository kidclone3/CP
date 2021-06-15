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
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<pair<int, int>> pq;
    FOR(n) {
        cin >> a[i];
        pq.push({-a[i], i});
    } 
    string ans(n, '0');
    ans[0] = '1';
    // So 1 luon luon thoa man.
    // Vi tri cua so' 1 nam o pq.top().
    int l, r;
    l = r = pq.top().second;
    pq.pop();
    FO(m, 2, n+1) {
        l = min(l, pq.top().second);
        r = max(r, pq.top().second);
        pq.pop();
        if (r-l+1 == m) {
            ans[m-1] = '1';
        }
    }
    cout << ans <<'\n';

}
