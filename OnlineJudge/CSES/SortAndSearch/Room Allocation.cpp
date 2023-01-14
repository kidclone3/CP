#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<tuple<int, int, int>> a(n);
    vector<int> ans(n, 0);
    set<pair<int, int>> room;
    for(int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        a[i] = {l, r, i};
    }
    sort(a.begin(), a.end());
    for (auto &[l, r, i] : a) {
        if (room.empty()) {
            ans[i] = 1;
            room.insert({r, 1});
        }
        else {
            auto it = room.lower_bound({l, -1});
            if (it == room.begin()) {
                ans[i] = room.size() + 1;
                room.insert({r, ans[i]});
            } else {
                --it;
                ans[i] = it->second;
                room.erase(it);
                room.insert({r, ans[i]});
            }
        }
    }
    cout << room.size() << "\n";
    for(auto &it: ans) cout << it << " ";
}
