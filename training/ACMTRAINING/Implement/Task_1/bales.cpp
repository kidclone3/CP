#include<bits/stdc++.h>
using namespace std;
int main() {

//  Bai nay chi la tinh trung binh cong.

    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) if (a[i] > sum/n) ans += a[i] - sum/n;
    cout << ans;
}
