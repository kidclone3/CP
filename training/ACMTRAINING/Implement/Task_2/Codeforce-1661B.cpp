#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(auto it : a) {
        // Cach lam: trau +1 & tim bit cuoi cung 
        int ans = 15;
        for(int j = 0; j < 15; ++j) {
            int tmp = it + j;
            if (tmp % (1<<15) == 0) ans = min(j, ans);
            int k;
            for(k = 0; k < 16; ++ k) {
                if (((tmp>>k) &1) || j-k > 15) break;
            }
            if ((1<<k) & tmp)
                ans = min(ans, 15-k+j);
        }
        cout << ans << " ";
    }
}
