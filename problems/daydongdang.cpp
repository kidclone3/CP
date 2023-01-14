#include<bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    pair<int, int> a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    for(int i = 0; i < n; ++i) cin >> b[i].first, b[i].second = i;

    sort(a, a+n);
    sort(b, b+n);

    map<int, int> mpa, mpb;
    for(int i =0; i < n; ++i) {
        mpa[a[i].first]++;
        mpb[b[i].first]++;
        if (a[i].second != b[i].second || mpa[a[i].first] != mpb[b[i].first]) return 0;
    }
    return 1;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}
// https://ideone.com/HXTuCX