#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> a(n);
    int sum = 0;
    int mx = INT_MIN;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, sum);
        sum = max(sum, 0);
    }
    if (mx < 0) {
        cout << "Losing streak.\n";
    }
    else {
        cout << "The maximum winning streak is " << mx << ".\n";
    }
}

int main() {
    int t;
    while(true) {
        cin >> t;
        if (t==0) break;
        solve(t);
    }
}