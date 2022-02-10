#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 1e3+5;
int t[N][N];
int n, q;

void update(int i, int j) {
    for(; i <= n; i += i & (-i)) {
        for(int v = j; v <= n; v += v & (-v)) {
            t[i][v] ++;
        }
    }
}

int get(int i, int j) {
    int res = 0;
    for(; i > 0; i -= i&(-i))
        for(int v = j; v > 0; v -= v&(-v)) 
            res += t[i][v];
    return res;
}

int solve() {
    cin >> n >> q;    
    FOR(n) {
        string s; cin >> s;
        FOR(j, n) {
            if (s[j] == '*') {
                update(i+1, j+1);
            }
        }
    }

    auto count = [&](int y1, int x1, int y2, int x2) {
        int topLeft = get(x1-1, y1-1);
        int botRight = get(x2, y2);

        int topRight = get(x2, y1-1);
        int botLeft = get(x1-1, y2);

        return botRight - topRight - botLeft + topLeft;
    };

    FOR(q) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << count(x1, y1, x2, y2) << '\n';
    }
    // cout << get(4, 3);
    return 0; 
}

int main()
{
    IOS;
    solve();
}