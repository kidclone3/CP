#include<bits/stdc++.h>
using namespace std;
#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_tree;
#define ll long long


int solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n+5);
    vector<int> pos(n+5);
    ordered_tree st;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i], pos[a[i]] = i;
        st.insert({i, a[i]});
    }
    int mn = 1, mx = n;
    ll sum = 0LL;
    while (m--) {
        int x; char ch;
        cin >> x >> ch;
        auto tmp = st.order_of_key({pos[x], x});
        sum += min(tmp, n - tmp -1) * 1LL;
        auto tmp2 = st.find_by_order(tmp);
        st.erase(tmp2);
        if (ch == 'l') {
            --mn;
            // cerr << pos[x] << '\n';
            pos[x] = mn;
        } else {
            ++mx;
            // cerr << pos[x] << '\n';
            pos[x] = mx;
        }
        st.insert({pos[x], x});
        // for (auto &it: st) cerr << it.first << " " << it.second << '\n';
        // cerr <<'\n';
    } 
    cout << sum;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}