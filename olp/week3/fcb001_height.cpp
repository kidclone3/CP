#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    int b[n];
    for(int i = 0; i < n; ++i) cin >> a[i], b[i] = a[i];
    sort(b, b+n);
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(b, b+n, a[i]) - b;
        if (b[it] == n || b[it] >= a[i]) it--;
        cout << it + 1 << " ";
    }
}