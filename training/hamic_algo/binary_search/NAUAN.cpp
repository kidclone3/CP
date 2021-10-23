#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) a[i] += a[i-1];
    }
    sort(a, a+n);
    int m; cin >> m;
    int p[m];
    for(int i = 0; i < m; ++ i) {
        int tmp;
        cin >> tmp;
        auto it = lower_bound(a, a+n, tmp);
        p[i] = it - a + 1;
        
    }
    for(int i = 0; i < m; ++i) cout << p[i] << " ";
}