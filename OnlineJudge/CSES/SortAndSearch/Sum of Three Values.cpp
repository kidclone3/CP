#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first; a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    // two pointer, with creative style (2 heads);
    for(int i = 1; i < n-1; ++i) {
        int remain = x - a[i].first;
        int l = 0, r = n-1;
        while (l < i && i < r) {
            int sum = a[l].first + a[r].first;
            if (sum == remain) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            }
            if (sum < remain) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE";
}
