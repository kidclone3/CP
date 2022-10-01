#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_tree;

int solve() {
    int n, k; cin >> n >> k;
    ordered_set st;
    for(int i = 0; i < n; ++i) {
        st.insert(i+1);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
