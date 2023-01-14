#include <bits/stdc++.h>
int n, m;
int main() {
    while(true) {
        scanf("%d%d", &n, &m);
        if (n==m && n == 0) break;
        if (n != 2 && m != 2) {
            int n_2_up = ceil(n*1.0/2);
            int n_2_low = n - n_2_up;
            int m_2_up = ceil(m*1.0/2);
            int m_2_low = m - m_2_up;
            printf("%d knights may be placed on a %d row %d column board.\n", n_2_up*m_2_up + n_2_low * m_2_low, n, m);
        }
        else {
            int mx;
            mx = (n == 2 ? m : n);
            int ans = 4 * (mx/4);
            int du = mx % 4;
            if (du == 3) du = 2;
            ans += du * 2;
            printf("%d knights may be placed on a %d row %d column board.\n", ans, n, m);
        }
    }
}
