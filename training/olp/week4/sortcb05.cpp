#include<bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
bool cmp(ii &a, ii &b) {
    return a.first == b.first ? a.second > b.second : a.first > b.first;
}

int main() {
    int m, n; cin >> n >> m;
    ii a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n, cmp);
    // for(int i = 0; i < n; ++i) {
    //     cout << a[i].first << " " << a[i].second << "\n";
    // }
    cout << a[m-1].first << " " << a[m-1].second;
}