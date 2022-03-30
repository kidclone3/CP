#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    // int a[n][n];
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x; 
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    int curr = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = n-1; j > -1; --j) {
            cout << ans[curr+j] << " \n"[j==0];
        }
        curr += n;
    }
}
