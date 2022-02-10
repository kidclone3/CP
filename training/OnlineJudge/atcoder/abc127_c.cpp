#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int dp[maxn];

int main() {
    int n, m, ans=0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        dp[l]++;
        dp[r+1]--;
    }
    for(int i = 1; i <= n; ++i) {
        dp[i] += dp[i-1];
        if (dp[i] >= m) ans++;
    }
    printf("%d", ans);
}