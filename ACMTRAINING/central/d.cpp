#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_tree; 
typedef tree<int, null_type,
less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multi_ordered_tree; 
// tree.find_by_order(x); tree.order_of_key(x); remove
// element in multi_ordered_tree: tree.erase(--tree.lower_bound(x));
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#define ar array
#define vt vector
#define all(v) begin(v), end(v)
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it = (s.begin()); it != (s.end()); ++it)
#define F_OR(i, a, b, s)                                                       \
  for (int i = (a); (s) > 0 ? i < (int)(b) : i > (int)(b); i += (s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n + 1, 1)
#define EACH(x, a) for (auto &x : a)

#define IOS                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

const int d4x[] = {-1, 0, 1, 0}, d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T> void print(T &x) {
  for (auto &it : x) {
    cerr << it << " ";
  }
  cerr << "\n";
};
template <class T> void printPair(T &x) {
  for (auto &it : x) {
    cerr << "(" << it.first << ", " << it.second << ") ";
  }
  cerr << "\n";
};


int block;

struct query {
    int L, R, pos;
};

bool cmp(query& a, query &b) {
    if (a.L/block != b.L/block) 
        return a.L/block < b.L/block;
    else 
        return a.R < b.R;
    
}

int solve() { 
    int n, q; 
    cin >> n >> q;
    block = sqrt(n);
    vi a(n);
    FOR(n) cin >> a[i];
    vt<query> qr(q);
    FOR(q) {
        cin >> qr[i].L >> qr[i].R;
        qr[i].L--;
        qr[i].R--;
        qr[i].pos = i;
    }
    sort(all(qr), cmp);
    // EACH(it, qr) cerr << it.L << " " << it.R << " " << it.pos << "\n";
    // cerr << '\n';
    int currL = -1, currR = -1;
    multi_ordered_tree st;
    vi ans(q);

    FOR(q) {
        int L = qr[i].L, R = qr[i].R;
        if (currL == -1) {
            currL = L;
            currR = R;
            FOR(j, currL, currR+1) st.insert(a[j]);
            
            // print(st);
            int mid = (st.size()-1)/2;
            int med = *st.find_by_order(mid);
            ans[qr[i].pos] = med;
            continue;
        }
        // cerr << currL << " "<<currR << " " <<qr[i].pos << '\n';
        // cerr << L << " " << R << "\n";
        // print(st);
        while (currL < L) {
            if (st.empty()) {
                currL = L;
                st.insert(a[currL]);
                break;
            }
            auto tmp = st.lower_bound(a[currL]);
            // cerr <<"currL < L " << *tmp << '\n';
            // cerr << *tmp << '\n';
            st.erase(--tmp);
            currL++;
        }
        while (currL > L) {
            currL--;
            st.insert(a[currL]);
        }
        currR = max(currR, currL);
        while (currR < R) {
            currR++;
            st.insert(a[currR]);
        }
        while (currR > R) {
            // if (st.lower_bound(a[currR]) != st.end())
            st.erase(--st.lower_bound(a[currR]));
            currR--;
        }
        // print(st);
        int mid = (st.size()-1)/2;
        int med = *st.find_by_order(mid);
        ans[qr[i].pos] = med;
    }
    EACH(it, ans) cout << it << "\n";
    return 0; 
}
int main() {
  IOS;
#ifndef ONLINE_JUDGE
  freopen("in1", "r", stdin);
  freopen("out1", "w", stdout);
#else
  // online submission
#endif
    solve();
  return 0;
}

