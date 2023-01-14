#include<bits/stdc++.h>
using namespace std;

int intervalSelection(vector<vector<int>> intervals) {
    // int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]; 
            });

    vector<vector<int>> busy = {{0, 0}, {0, 0}};
    int ans = 0;
    for(auto it : intervals) {
        if (it[0] > busy[1][1]) {
            busy[1] = it;
            ans++;
        } else {
            if (it[0] > busy[0][1]) {
                busy[0] = it;
                ans++;
            }
            if (busy[0][1] > busy[1][1]) {
                swap(busy[0], busy[1]);
            }
        }
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(2));
        for(int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        cout << intervalSelection(a) << '\n';
    }
}
