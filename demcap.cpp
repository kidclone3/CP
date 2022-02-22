#include<bits/stdc++.h>
using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    vector<int> x(n), y(m);
    int cntX[1000+5], cntY[1000+5];

    // memset(cntX, 0, sizeof cntX);
    fill(cntX, cntX+1000+5, 0);
    fill(cntY, cntY+1000+5, 0);

    for(int i = 0; i < n; ++i) cin >> x[i], cntX[x[i]]++;
    for(int i = 0; i < m; ++i) cin >> y[i], cntY[y[i]]++;
    
    // x^y > y^x 
    // => ylogx > xlogy 
    // i^j > j^i them vo mang cua preCal[i].push_back(j);
    //     nguoc lai them vo mang cua preCal[j].push_back(i);
    // 1^0 > 0^1 
// ans = answer

    long long ans = 0;

    // Cong toan bo mang X.
    if (cntY[0]) ans += n - cntX[0];

    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j <= 1000; ++j) { 
            if ((double) j*log(i) > i*log(j)) ans += 1LL * cntX[i] * cntY[j];
        }
    }

    cout << ans;
    return 0;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
