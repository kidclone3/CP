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
const int maxn = 1e5+5;
int n, m, q_l, q_r, chiso;

struct node{
    int change, num;
    node() {
        change = 0;
        num = 0;
    }
} st[4*maxn];

void down(int id) {
    st[2*id].change ^= 1;
    st[2*id+1].change ^= 1;
    st[id].change = 0;
}

void update(int id, int l, int r) {
    // Neu ngoai tam + can update => chung ta se update.
    if (r < q_l || q_r < l) {
        if (st[id].change) {
            st[id].num = r-l+1 - st[id].num;
            down(id);
        }
        return;
    }
    // TH nam hoan toan trong vung minh xet.
    if (q_l <= l && r <= q_r) {
        st[id].change ^= 1;
        if (st[id].change) {
            st[id].num = r-l+1 - st[id].num;
            down(id);
        }
        return;
    }
    // Th chi nam 1 phan
    if (st[id].change) {
        st[id].num = r-l+1 - st[id].num;
        down(id);
    }
    int mid = (l+r)/2;
    update(2*id, l, mid);
    update(2*id+1, mid+1, r);
    // Cap nhat so luong o nut cha
    st[id].num = st[2*id].num + st[2*id+1].num;
}

int get(int id, int l, int r) {
    // Ham get thi cung nhu update. Neu nam ngoai tam + co' dau hieu thay doi => thay.
    if (r < q_l || q_r < l) {
        if (st[id].change) {
            st[id].num = r-l+1 - st[id].num;
            down(id);
        }
        return 0;
    }
    // Neu nam trong hoan toan thi tra ve gtri cua vi tri do.
    if (q_l <= l && r <= q_r) {
        if (st[id].change) {
            st[id].num = r-l+1 - st[id].num;
            down(id);
        }
        return st[id].num;
    }
    // TH ko nam hoan toan thi sao?
    if (st[id].change) {
        st[id].num = r-l+1 - st[id].num;
        down(id);
    }
    int mid = (l+r)/2;
    return get(2*id, l, mid) + get(2*id+1, mid+1, r);
}

void solve(){
    cin >> n >> m;
    FOR(m) {
        cin >> chiso >> q_l >> q_r;
        if (chiso == 0) {
            update(1, 1, n);
            // FOR(j, 1, 4*n+1) {
            //    printf("Node %d: State = %d, Number = %d\n", j, st[j].change, st[j].num);
            // }
            // printf("\n");
        }
        else {
            cout << get(1, 1, n) << '\n';
        }
    }
}

int main()
{
    IOS;
    solve();
}