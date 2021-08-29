// https://codeforces.com/contest/380/problem/C
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pair<int, int>>
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
string s;
const int MAXN = 4*1e6+5;
struct Node{
    int optimal, open, close;
    Node() {
        optimal = open = close = 0;
    }
    Node(int optimal, int open, int close) {
        this->optimal = optimal;
        this->open = open;
        this->close = close;
    }
};
Node operator + (const Node& left, const Node& right) {
    Node res;
    
    // min so' dau' ( thua` ra ben trai va dau ) thua ra ben phai
    int tmp = min(left.open, right.close);

    // Neu thao tac ghep 2 Node tao ra nhieu hon cap ngoac => them vao optimal
    res.optimal = left.optimal + right.optimal + tmp;

    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}

Node ST[MAXN];

// Ta se khoi tao cay nhu sau:
void build(int id, int l, int r) {
    if (l == r) {
        if (s[l-1] == '(') ST[id] = Node(0, 1, 0);
        else if (s[l-1] == ')') ST[id] = Node(0, 0, 1);
        // cout << ST[id].optimal << " " << ST[id].open << " " <<ST[id].close << '\n';
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    ST[id] = ST[2*id] + ST[2*id+1];
}

Node query(int id, int l, int r, int u, int v) {
    // TH ko giao nhau.
    if (v < l || r < u) return Node(0, 0, 0);

    // TH [l,r] nam hoan toan trong [u,v]
    if (u <= l && r <= v) return ST[id];

    int mid = (l+r)/2;
    return query(2*id, l, mid, u, v) + query(2*id+1, mid+1, r, u, v);
}

void solve() {
    cin >> s;
    int n = s.size();
    // while(__builtin_popcount(n) != 1) {
    //     n++;
    //     s.push_back('&');
    // }
    build(1, 1, n);
    int k; cin >> k;
    FOR(k) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b).optimal * 2 <<'\n';
    }
    // FOR(4*n+1) cout << ST[i].optimal << " " << ST[i].open << " " <<ST[i].close << '\n';
}

int main()
{
    IOS;
    solve();
}

