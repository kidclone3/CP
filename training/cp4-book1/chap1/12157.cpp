#include<bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mile, juice;
    mile = juice = 0;
    for(int i = 0; i < n; ++i) {
        mile += (a[i] / 30 + 1) * 10;
        // if (a[i] % 30 != 0) mile += 10;
        juice += (a[i] / 60 + 1) * 15;
        // if (a[i] % 60 != 0) juice += 15;
    }
    if (mile < juice) cout << "Mile " << mile << '\n';
    else if (mile > juice) cout << "Juice " << juice << '\n';
    else cout << "Mile Juice " << mile << '\n';
    return 0; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": ";
        solve();
    }
}
