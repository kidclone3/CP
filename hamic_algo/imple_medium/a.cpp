#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = INT_MIN; 
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        cout << mx << " ";
    }    
}