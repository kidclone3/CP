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
#define maxn 50005

struct node{
    ll sum, prefix, suffix, best;
    node() {
        sum = prefix = suffix = best = 0;
    }
    node(ll val) {
        sum = prefix = suffix = best = val;
    }
    node operator + (const node& _right) {
        node result;
        result.sum = sum + _right.sum;
        result.prefix = max(prefix, sum + _right.prefix);
        result.suffix = max(_right.suffix, _right.sum + suffix);
        result.best = max(max(best, _right.best), suffix + _right.prefix);
        return result;
    }
} st[4*maxn];

int n, m;
ll a[maxn];
int q_l, q_r;
void build(int id = 1, int l = 1, int r = n) {
    if (l > r) return;
    if (l == r) {
        st[id] = node(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    node left = st[2*id];
    node right = st[2*id+1];
    st[id] = left + right;
}

node get(int id = 1, int l = 1, int r = n) {
    if (r < q_l || q_r < l) return node(1LL * INT_MIN);
    if (q_l <= l && r <= q_r) return st[id];
    int mid = (l+r)/2;
    node left = get(2*id, l, mid);
    node right = get(2*id+1, mid+1, r);
    return left + right;
}

void solve(){
    cin >> n;
    FOR(i, 1, n+1) {
        cin >> a[i];
    }
    build();
    cin >> m;
    FOR(m) {
        cin >> q_l >> q_r;
        cout << get().best << "\n";
    }
}

int main()
{
    IOS;
    solve();
}