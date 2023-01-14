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
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

struct Trie {
    // f = finish = số xâu kết thúc tại node này.
    // g = số xâu đi qua node này.
    int f, g;
    Trie * c[2];
    Trie() {
        c[0] = c[1] = NULL;
        f = g = 0;
    }
};

Trie* root = new Trie();

int layer = 0;

void dfs(Trie *a = root) {
    a->g = a->f;
    FOR(i, 2) {
        if (a->c[i] != NULL) {
            layer ++;
            dfs(a->c[i]);
            layer --;
            a->g += a->c[i]->g;
        }
    }
}

void TrieInsert(const vi &a) {
    Trie *p = root;
    int n = a.size();
    FOR(n) {
        if (p->c[a[i]] == NULL) p->c[a[i]] = new Trie();
        p = p->c[a[i]];
    }
    p->f++;
}

int solve() {
    int m, n; cin >> m >> n;
    FOR(j, m) {
        int nn; cin >> nn;
        vi b(nn);
        FOR(nn) cin >> b[i];
        TrieInsert(b);
    }
    dfs();
    FOR(j, n) {
        int nn; cin >> nn;
        vi c(nn);
        FOR(nn) cin >> c[i];
        Trie* p = root;
        int i, ans = 0;
        for(i = 0; i < nn; ++i) {
            if (p->c[c[i]] == NULL) break;
            p = p->c[c[i]];
            ans += p->f;
        }
        if (i == nn) ans += p->g - p->f;
        cout << ans << "\n";
    }
    return 0; 
}

int main()
{
    IOS;
    solve();
}