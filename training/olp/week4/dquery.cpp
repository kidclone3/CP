#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

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

struct dat {
    int i, j, type, id;
};

const int N = 1e5+5, Q = 1e5+5, A = 1e6+5;
int n, q, res[Q], last_pos[A], bit[N];
dat a[N+Q];

bool cmp(dat u, dat v) {
    return (u.j < v.j || (u.j == v.j && u.type < v.type));
}

void update(int x, int k) {
    for(x; x <= n; x+= x&-x) bit[x] += k;
}

int get(int x) {
    int ans = 0;
    for(x; x > 0; x-= x & -x) ans += bit[x];
    return ans;
}

void solve() {
    cin >> n;     cin >> q;
    FOR1(n) cin >> a[i].i, a[i].j = i, a[i].type = -1;

    FOR1(q) cin >> a[i+n].i >> a[i+n].j, a[i+n].id = i;

    sort(a+1, a+n+q+1, cmp);

    FOR1(n+q) {
        if (a[i].type == -1) {
            update(a[i].j, 1); // Add size of array to 1
            if (last_pos[a[i].i] > 0) update(last_pos[a[i].i], -1); 
            last_pos[a[i].i] = a[i].j;
        } else {
            res[a[i].id] = get(a[i].j) - get(a[i].i-1);
        }
    }
    FOR1(q) cout << res[i] << "\n";
}

int main()
{
    IOS;
    solve();
}