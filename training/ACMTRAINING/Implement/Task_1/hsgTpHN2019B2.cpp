#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<long long> p(m);
    // l[i] tang x[i], l[i+1] giam x[i];
    for(int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    // 10^4 => 10^8 la` chay dc trong 1s.
    for(int i = 0; i < n; ++i) {
        long long l, r, x;
        cin >> l >> r >> x;
        for(int j = l; j <= r; ++j) {
            if ((j - l) & 1) p[j] -= x;
            else p[j] += x;
        }
    }

    // We could use another way to solve this problem. 
    // sort by l.

    for(int i = 0; i < m; ++i) {
        cout << p[i] << " ";
    }
}
