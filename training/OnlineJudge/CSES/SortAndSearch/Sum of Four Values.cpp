#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i+1;
    sort(a.begin(), a.end());
    for(int i = 1; i < n-1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int l = 0, r = n-1;
            int remain = x - a[i].first - a[j].first;
            while (l < i && j < r) {
                int sum = a[l].first + a[r].first;
                if (sum == remain) {
                    cout << a[l].second << " " << a[r].second << " " << a[i].second << " " << a[j].second;
                    return 0;
                }
                if (sum < remain) l++;
                else r--;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
