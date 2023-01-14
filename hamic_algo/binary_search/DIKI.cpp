#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n; ++i) {
        auto tmp = lower_bound(a, a+n, a[i]+m);
        if (a[i] + m == *tmp)
            return !(cout << a[i] << " " << a[i]+m);
    }
    cout << "-1";
    return 0;
}