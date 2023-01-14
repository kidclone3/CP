#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int cnt = 0;
    while (n) {
        string s = to_string(n);
        int mx = -1;
        for(auto &it: s) mx = max(mx, it-'0');
        cnt++;
        n -= mx;
        // cerr << mx << " ";
    }
    cout << cnt;
}
