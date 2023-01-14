#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
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
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    string s; cin >> s;
    int n = s.size();
    ordered_set chan, le, d_chan, d_le;
    FOR(n) {
        if (s[i] == ']' || s[i] == '[') {
            if (i&1) chan.insert(i+1);
            else le.insert(i+1);
            if (i && (s[i-1] == ']' || s[i-1] == '[')) {
                if (i&1) d_chan.insert(i+1);
                else d_le.insert(i+1);
            }
        }
    }
    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int lb_c = chan.order_of_key(l);
        int ub_c = chan.order_of_key(r);
        if (*chan.find_by_order(ub_c) > r) ub_c--;
        int lb_l = le.order_of_key(l);
        int ub_l = le.order_of_key(r);
        if (*le.find_by_order(ub_l) > r) ub_l--;
        int lb_d, ub_d;
        if (l & 1) {
            lb_d = d_chan.order_of_key(l);
            ub_d = d_chan.order_of_key(r);
            if (*d_chan.find_by_order(ub_d) > r) ub_d--;
        } else {
            lb_d = d_le.order_of_key(l);
            ub_d = d_le.order_of_key(r);
            if (*d_le.find_by_order(ub_d) > r) ub_d--;
        }
        int ans = 0;
        if (ub_c >= lb_c) {
            ans += ub_c - lb_c + 1;
        }
        if (ub_l >= lb_l) {
            ans += ub_l - lb_l + 1;
        }
        if (ub_d >= lb_d) {
            ans -= (ub_d - lb_d + 1) * 2;
        }
        cout << ans << "\n";
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}