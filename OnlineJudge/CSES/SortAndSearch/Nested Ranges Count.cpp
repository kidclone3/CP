#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
// #pragma GCC optimize("O3,unroll-loops")

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

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

struct range {
    int l, r, index;
    bool operator < (const range &other) {
        return l == other.l ? r > other.r : l < other.l;
    }
};

int solve() {
    int n; cin >> n;
    vector<range> ranges(n);
    vi contains(n);
    vi contained(n);
    ordered_set<pair<int, int>> rightBoundaries;

    FOR(n) {
        int l, r; cin >> l >> r;
        ranges[i].l = l;
        ranges[i].r = r;
        ranges[i].index = i;
    }
    sort(all(ranges));
    FOR(n) {
        rightBoundaries.insert({ranges[i].r, -1*i});
        contained[ranges[i].index] = rightBoundaries.size() - rightBoundaries.order_of_key({ranges[i].r, -1*i}) - 1;
    }
    rightBoundaries.clear();
    FOR(i, n-1, -1, -1) {
        rightBoundaries.insert({ranges[i].r, -1*i});
        contains[ranges[i].index] = rightBoundaries.order_of_key({ranges[i].r, -1*i});
    }
    // print(contains);
    EACH(it, contains) {
        cout << (it > 0 ? 1 : 0) << " ";
    }
    cout << "\n";
    EACH(it, contained) {
        cout << (it > 0 ? 1 : 0) << " ";
    }
    return 0; 
}

int main()
{
    IOS;
    solve();
}