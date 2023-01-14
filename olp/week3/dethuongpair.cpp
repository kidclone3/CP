#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    set<pair<int, int>> st;
    pair<int, int> ans;
    int mx = 0;
    ans = {-1, -1};
    for(int i = 0; i <n; ++i) {
        cin >> a[i];
        if (!st.empty()) {
            if (a[i] - st.begin()->first > mx) {
                mx = a[i] - st.begin()->first;
                ans = {st.begin()->second, i};
            }
        }
        st.insert({a[i], i});
    }
    cout << ans.first +1 << " " << ans.second + 1 << "\n";
    cout << mx;
    
}