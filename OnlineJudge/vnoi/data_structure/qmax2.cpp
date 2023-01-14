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

struct Node{
    int lazy, val;
};



const int MAXN = 50000+5;

Node node[4*MAXN];

void down(int id) {
    int t = node[id].lazy;
    node[2*id].lazy += t;
    node[2*id].val += t;

    node[2*id+1].lazy += t;
    node[2*id+1].val += t;

    node[id].lazy = 0;
}

void update(int id, int l, int r, int q_l, int q_r, int val) {
    if (q_r < l || r < q_l) return;
    if (q_l <= l && r <= q_r) {
        node[id].lazy += val;
        node[id].val += val;
        return;
    }
    int mid = (l+r) /2;
    down(id);

    update(2*id, l, mid, q_l, q_r, val);
    update(2*id+1, mid+1, r, q_l, q_r, val);

    node[id].val = max(node[2*id].val, node[2*id+1].val);
}

int get(int id, int l, int r, int q_l, int q_r) {
    if (q_r < l || r < q_l) return INT_MIN;
    if (q_l <= l && r <= q_r) return node[id].val;

    int mid = (l+r)/2;
    down(id);
    return max(get(2*id, l, mid, q_l, q_r), get(2*id+1, mid+1, r, q_l, q_r));
}


void solve(){
    int n, q;
    cin >> n >> q;
    FOR(q) {
        int a, b, c, d;
        cin >> a >> b >> c;
        if (a == 0) {
            cin >> d;
            update(1, 1, n, b, c, d);
        }
        else {
            cout << get(1, 1, n, b, c) << "\n";
        }
    }
}

int main()
{
    IOS;
    solve();
}