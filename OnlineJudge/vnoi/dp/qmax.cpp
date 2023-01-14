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
const int MAXN = 50000 + 5;
int n, m, q;
ll st[4*MAXN], vt[MAXN];

void update(int i, ll val) {
    int id = 1, l = 1, r = MAXN; 
    while(true) {
        st[id] = max(st[id], val);
        if (l >= r) return;
        int mid = (l+r) / 2;
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

ll get(int id, int l, int r, int q_l, int q_r) {
    if (r < q_l || q_r < l) return 0LL;
    if (q_l <= l && r <= q_r) return st[id];
    int mid = (l+r)/2;
    return max(get(2*id,l, mid, q_l, q_r), get(2*id+1, mid+1, r, q_l, q_r));
}

void solve(){
    cin >> n >> m;
    FOR(m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        vt[a] += c;
        vt[b+1] -= c;
    }

    FOR(i, 0, MAXN) {
        if (i)
            vt[i] += vt[i-1];
        if (vt[i]) update(i, vt[i]);
    }
   
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, MAXN, l, r) << "\n";
    }
}

int main()
{
    IOS;
    solve();
}