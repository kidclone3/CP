#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
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
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};

const int MAXN = 3*1e4+5;
vi st[4*MAXN], a(MAXN);

void build(int id, int l, int r) {
    // if (i < l || i > r) return;
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    st[id].resize(st[2*id].size() + st[2*id+1].size());
    merge(all(st[2*id]), all(st[2*id+1]), st[id].begin());
}

int get(int id, int l, int r, int q_l, int q_r, int k) {
    if (q_r < l || r < q_l) return 0;
    if (q_l <= l && r <= q_r) 
        return st[id].size() - (upper_bound(all(st[id]), k) - st[id].begin());
    int mid = (l+r)/2;
    return get(2*id, l, mid, q_l, q_r, k) + get(2*id+1, mid+1, r, q_l, q_r, k);
}

void solve(){
    int n;
    cin >> n;
    FOR(n) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    // FOR(n) print(st[i]);
    int q; cin >> q;
    FOR(q) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        cout << get(1, 0, n-1, l, r, k) << "\n";
    }
}

int main()
{
    IOS;
    solve();
}