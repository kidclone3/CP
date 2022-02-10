#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
#pragma GCC optimize("O3,unroll-loops")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int) (b) : i > (int) (b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
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
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 1e5+5;

multiset<int> ST[4*N];

int arr[N];

void update(int id, int l, int r, int i, int val, int rev) {
    if (r < i || i < l) return;
    if (l == r) {
        if (rev != -1)
            ST[id].erase(ST[id].find(rev));
        ST[id].insert(val);
        return;
    }
    if (l <= i && i <= r) {
        if (rev != -1)
            ST[id].erase(ST[id].find(rev));
        ST[id].insert(val);
        // return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, i, val, rev);
    update(2*id+1, mid + 1, r, i, val, rev);
}

int get(int id, int l, int r, int u, int v, int k) {
    if (r < u || v < l) return INT_MAX;
    if (u <= l && r <= v) {
        auto it = ST[id].lower_bound(k);
        return it == ST[id].end() ? INT_MAX : *it;
    }
    int mid = (l+r)/2;
    return min(get(2*id, l, mid, u, v, k), get(2*id+1, mid+1, r, u, v, k));
}

int solve() {
    int n, m; cin >> n >> m;
    FOR1(n) {
        cin >> arr[i];
        update(1, 1, n, i, arr[i], -1);
    }
    FOR(m) {
        int a,b,c,d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(1, 1, n, b, c, arr[b]);
            arr[b] = c;
        } else {
            cin >> b >> c >> d;
            int ans = get(1, 1, n, b, c, d);
            cout << (ans == INT_MAX ? -1 : ans) << "\n";
        }
    }
    // FOR(n+1) cout << arr[i] << " ";
    return 0; 
}

int main()
{
    IOS;
    solve();
}