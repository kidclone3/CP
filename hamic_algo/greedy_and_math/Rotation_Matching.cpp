#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> aa(n+5), bb(n+5);
    vector<int> c(n+5, 0);
    // Mảng aa, bb, c có n phần tử.
    // Khởi tạo mảng c như này thì toàn bộ phần tử = 0 hết.
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        aa[tmp] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        bb[tmp] = i;
    }
    for(int i = 1; i <= n; ++i) {
        c[(aa[i] >= bb[i] ? aa[i] - bb[i] : aa[i] - bb[i] + n)]++;
    }
    int mx = INT_MIN;

    for (auto &it: c) {
        mx = max(mx, it);
    }
    cout << mx;
}
