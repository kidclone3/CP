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

const int MAXN = 2*1e5 + 5;
ll st[4*MAXN], c[4*MAXN];

void down(int id) {
    ll t = c[id];

    st[2*id] += t;
    c[2*id] += t;

    st[2*id+1] += t;
    c[2*id+1] += t;

    c[id] = 0LL;
}

void update(int id, int l, int r, int q_l, int q_r, int val) {
    if (q_r < l || r < q_l) return;
    if (l > r) return;
    if (q_l <= l && r <= q_r) {
        st[id] += val;
        c[id] += val;
        return;
    }
    int mid = (l+r)/2;
    down(id);
    update(2*id, l, mid, q_l, q_r, val);
    update(2*id+1, mid+1, r, q_l, q_r, val);

    st[id] = max(st[2*id], st[2*id+1]);
}

ll get(int id, int l, int r, int pos) {
    if (l > r) return LLONG_MIN;
    if (pos < l || r < pos) return LLONG_MIN;
    if (l == r) return st[id];
    down(id);
    int mid = (l+r)/2;
    return max(get(2*id, l, mid, pos), get(2*id+1, mid+1, r, pos));
} 

void solve(){
    int n, q;
    cin >> n >> q;
    FOR(n) {
        ll a; cin >> a;
        update(1, 1, n, i+1, i+1, a);
    }
    FOR(q) {
        int query; cin >> query;
        if (query == 1) {
            int l, r;
            ll val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            int pos;
            cin >> pos;
            cout << get(1, 1, n, pos) << "\n";
        }
    }
    // FOR(i, 1, 4*n+1) {
    //     cout << st[i] << " " << c[i] << "\n";
    // }
}

int main()
{
    IOS;
    solve();
}