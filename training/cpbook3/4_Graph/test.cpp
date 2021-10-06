#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, bp, i, sodao, du, dem=0;
    cin >> m >> n;
    for(i = m; i <= n; i++) {
        bp = i; sodao = 0;
        while(bp > 0) {
            du = bp % 10;
            bp = bp / 10;
            sodao = sodao * 10 + du;
        }
        if (i == sodao) dem++;
    }
    cout << dem;
}