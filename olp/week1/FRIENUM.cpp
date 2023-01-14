#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    int cnt = 1;
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) cnt++;
        else if (cnt != 1) ans += cnt, cnt = 1;
    }
    if (cnt != 1) ans += cnt;
    cout << ans;
}