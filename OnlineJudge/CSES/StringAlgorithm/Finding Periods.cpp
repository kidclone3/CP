#include <bits/stdc++.h>
using namespace std;

int solve() {
    string s; cin >> s;
    // Z algorithm
    // Calculate z function 
    int n = s.size();
    vector<int> Z(n+5, 0);
    for(int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            Z[i] = min(Z[i-l], r-i+1);
        while (i + Z[i] < n && s[i+Z[i]] == s[Z[i]]) 
            Z[i]++;
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }
    for (int i = 0; i < n; ++i) 
        if (i + Z[i] >= n) cout << i << " ";
    cout << n;
    return 0;
}

int main() {
    solve();
    return 0;
}
