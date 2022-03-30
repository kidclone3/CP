#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], ans[n];
    int curr = INT_MIN;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        curr = max(curr, a[i]);
        ans[i] = curr;
    }
    for(int i = 0; i < n; ++ i) {
        cout << ans[i] << " ";
    }
}
