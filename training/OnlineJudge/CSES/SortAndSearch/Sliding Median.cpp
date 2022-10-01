#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    ordered_set st;
    int mid = k/2;
    if (k%2 == 0) mid--;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }    

    for(int i = 0; i < k; ++i) {
        st.insert(a[i]);
    }
    cout << *st.find_by_order(mid) << " ";
    
    // cerr << "\n";
    // for(auto &it: st) cerr << it << " ";
    
    for(int i = k; i < n; ++i) {
        st.insert(a[i]);
        st.erase(--st.lower_bound(a[i-k]));
        cout << *st.find_by_order(mid) << " ";

        // cerr << "\n";
        // for(auto &it: st) cerr << it << " ";
    }
    // cerr << "\n";
    // for(auto &it: st) cerr << it << " ";
}
