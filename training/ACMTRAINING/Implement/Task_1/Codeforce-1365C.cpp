#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<int> mp1(n+5), mp2(n+5);
    for(int i = 0; i < n; ++ i) {
        cin >> a[i];
        mp1[a[i]]=i;
    }
    for(int i = 0; i < n; ++ i) {
        cin >> b[i];
        mp2[b[i]]=i;
    }
    vector<int> ans(2*n+5, 0);
    for(int i = 1; i < n+1; ++i) {
        if (mp1[i] < mp2[i]) {
            ans[mp1[i]-mp2[i]+n]++;
        }
        else {
            ans[mp1[i]-mp2[i]]++;
            ans[mp1[i]-mp2[i]+n]++;
        }
        // for(int j = 0; j <= n+5; ++j) cout << ans[j] << " \n"[j==n+5];
    }
    // for(int i = 0; i <= n+5; ++i) cout << ans[i] << " ";
    cout << *max_element(ans.begin(), ans.end());
}
