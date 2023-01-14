#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<bits/extc++.h>

using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_tree; typedef tree<int, null_type,
// less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// multi_ordered_tree; tree.find_by_order(x); tree.order_of_key(x); remove
// element in multi_ordered_tree: tree.erase(--tree.lower_bound(x));
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

const int N = 4e5+5;
vector<pair<int, int>> a;
vector<int> tree[N];
int n;

void buildTree (int treeIndex, int l, int r) {
    /* l => start of range,
        r => ending of a range
        treeIndex => index in the Segment Tree/Merge
                     Sort Tree  */
 
    /* leaf node */
    if (l == r) {
        tree[treeIndex].push_back(a[l].se);
        return;
    }
    int mid = (l+r) >> 1;
    buildTree(treeIndex << 1, l, mid);
    buildTree(treeIndex << 1 | 1, mid + 1, r);
    merge(all(tree[treeIndex << 1]), all(tree[treeIndex << 1 | 1]), back_inserter(tree[treeIndex]));
}

// return Kth smallest number in range 
int queryRec(int segmentStart, int segmentEnd, int queryStart, int queryEnd, int treeIndex, int K) {
    
    /*
        segmentStart => start of a Segment,
        segmentEnd   => ending of a Segment,
        queryStart   => start of a query range,
        queryEnd     => ending of a query range,
        treeIndex    => index in the Segment
                        Tree/Merge Sort Tree,
        K  => kth smallest number to find  
    */
    if (segmentStart == segmentEnd) return tree[treeIndex][0];
    int mid = (segmentStart + segmentEnd) >> 1;

    // finds the last index in the segment
    // which is <= queryEnd

    int last_in_query_range = upper_bound(all(tree[treeIndex << 1]), queryEnd) - begin(tree[treeIndex << 1]);

     // finds the first index in the segment
    // which is >= queryStart
    int first_in_query_range = lower_bound(all(tree[treeIndex << 1]), queryStart) - begin(tree[treeIndex << 1]);
    int M = last_in_query_range - first_in_query_range;

    if (M >= K) return queryRec(mid + 1, segmentEnd, queryStart, queryEnd, treeIndex << 1, M - K);
    else return queryRec(segmentStart, mid, queryStart, queryEnd, treeIndex << 1 | 1, K - M);
}

// wrapper 
int query(int queryStart, int queryEnd, int K) {
    return queryRec(0, n-1, queryStart, queryEnd, 1, K);
}

int solve() { 
    int q;
    cin >> n >> q;
    vi arr(n);
    FOR(n) {
        cin >> arr[i];
        a.push_back({arr[i], i});
    }
    sort(all(a));
    buildTree(1, 0, n-1);
    FOR(q) {
        int l, r; cin >> l >> r;
        l--, r--;
        // int mid = (l+r)/2 - l + 1;
        int median = query(l, r, 0);
        cout << arr[median] << '\n';
    }
    FOR(n) print(tree[i]);
    return 0; 

}
int main() {
  IOS;
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
#else
  // online submission
#endif
  
  solve();
  return 0;
}

