#include <bits/stdc++.h>
int main() {
    int n, i, j;
    while (scanf("%d%d%d", &n, &i, &j) != EOF) {
        int ans = 1;
        while(true) {
            i++, j++;
            i >>= 1; j >>= 1;
            if (i == j) break;
            else ans++;
        }
        printf("%d\n", ans);
    }
}
