#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        int l = i+1;
        int r = n-1;
        int tmp = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            // Thu hep can tren
            if (a[mid].first >= a[i].second) r = mid - 1;
            else {
                l = mid + 1;
                tmp = mid;
            }
        }
        if (tmp) ans += tmp - i;
    }
    cout << ans;
}