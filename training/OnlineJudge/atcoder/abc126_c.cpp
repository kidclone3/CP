#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k; 
    scanf("%d%d", &n, &k);
    double ans = 0.0;
    // cout << ans <<"\n";
    if (n >= k) {
        ans += 1.0*(n-k+1)/n;
    }
    for (int i = 1; i < min(n+1, k); ++i) {
        ans += 1.0/(1.0*n) * pow(0.5, (int) log2((k-1)/i) + 1);
    }
    printf("%.12f",ans);
}