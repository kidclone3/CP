#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if (a>=b) return a;
    else return b;
}

int main() {
    char a1[1250], b1[1250], ans[1250];
    // gets(a);
    // gets(b);
    char a[1250] = "00012345423";
    char b[1250] = "013121245334";
    for (int i = 0; i < 1230; i++)
    {
        a1[i] = b1[i] = '0';
    }
    int n = strlen(a);
    int m = strlen(b);
    for (int i = n-1; i >= 0; i--)
    {
        a1[i] = a[n-i-1];
    }
    for (int i = m-1; i >= 0; i--)
    {
        b1[i] = b[m-i-1];
    }
    int du = 0;
    int mx = max(n, m);
    for(int i = 0; i < mx + 1; ++i) {
        int tmp = a1[i] + b1[i] - 2*'0' + du;
        if(tmp >= 10) {
            du = 1;
            tmp /= 10;
        }
        ans[i] = tmp + '0';
    }
    if(ans[mx] == '1') mx++;
    for(int i = mx - 1; i >= 0; --i) {
        printf("%c", ans[i]);
    }
    return 0;
}
