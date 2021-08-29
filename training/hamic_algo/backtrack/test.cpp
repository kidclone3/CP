#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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
    int n, k;
    cin >> n >> k;
    vector<pair<int, pii>> a(n);
    FOR(n) {
        int l, r;
        cin >> l >> r;
        a[i] = {r, {l, i}};
        // theo thứ tự bi, ai, i
    }
    sort(all(a));
    // Tách ra 1 mảng b cho khỏe
    vi b(n);
    FOR(n) {
        b[i] = a[i].first;
    }
    // đầu tiên cần tìm vị trí của r.
    int r = upper_bound(all(b), b[0] + k) - b.begin() - 1;
    multiset<pii> st; // chứa ai trong đoạn b[i], b[i]+k
    FOR(i, r+1) {
        st.insert(a[i].second);
    }
    int mx = st.rbegin()->first - st.begin()->first;
    pii pos ={st.begin()->second, st.rbegin()->second};
    // Ok, bắt đầu dùng two pointer.
    FOR(i, 1, n){
        st.erase(a[i-1].second);
        int rr = upper_bound(all(b), b[i] + k) - b.begin() - 1;
        for(; r <= rr; ++r) {
            st.insert(a[r].second);
        }
        int tmp = st.rbegin()->first - st.begin()->first;        
        if (tmp > mx) {
            mx = tmp;
            pos ={st.begin()->second, st.rbegin()->second};
        }
    }
    cout << pos.first << " " << pos.second;
}
