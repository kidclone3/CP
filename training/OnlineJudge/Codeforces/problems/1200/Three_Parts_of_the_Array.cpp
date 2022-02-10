// https://codeforces.com/contest/1006/problem/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l, r; l = 0, r = n-1;
    long long sum1, sum2, ans;
    sum1 = sum2 = ans = 0;
    while(l <= r) {
        if (sum1 < sum2) {
            sum1 += a[l++];
            
        }
        else if (sum1 > sum2) {
            sum2 += a[r--];
            
        }
        else {
            ans = sum1;
            if (l == r) break;
            sum1+=a[l++];
            sum2+=a[r--];
        }
        // cout << l << " " << r << "\n";
    }
    if (sum1 == sum2) ans = sum1;
    cout << ans;
}