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

const int MAXN = 5*1e4+5;
vi mn(4*MAXN, INT_MAX), mx(4*MAXN, 0);
void build(int i, int val) {
    int id, l, r;
    id = 1;
    l = 1, r = MAXN;
    while(true) {
        mn[id] = min(mn[id], val);
        mx[id] = max(mx[id], val);
        if (l >= r) return;
        int mid = (l+r)/2;
        if (mid >= i) {
            id = 2*id;
            r = mid;
        }
        else {
            id = 2*id+1;
            l = mid+1;
        }
    }
}
int get_min(int id, int l, int r, int q_left, int q_right) {
    if (r < q_left || l > q_right) return INT_MAX;
    if (q_left <= l && r <= q_right) return mn[id];
    int mid = (l+r)/2;
    return min(get_min(2*id, l, mid, q_left, q_right), get_min(2*id+1, mid+1, r, q_left, q_right));
}
int get_max(int id, int l, int r, int q_left, int q_right) {
    if (r < q_left || l > q_right) return INT_MIN;
    if (q_left <= l && r <= q_right) return mx[id];
    int mid = (l+r)/2;
    return max(get_max(2*id, l, mid, q_left, q_right), get_max(2*id+1, mid+1, r, q_left, q_right));
}
void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    FOR(n) {
        cin >> a[i];
        build(i+1, a[i]);
    }
    // print(a);
    FOR(q) {
        int l, r;
        cin >> l >> r;
        cout << get_max(1, 1, MAXN, l, r) - get_min(1,1,MAXN, l, r) << "\n";
    }
}

int main()
{
    IOS;
    solve();
}