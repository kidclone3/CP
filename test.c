#include<stdio.h>
int main() {
    int x = 0;
    int n = 1000086;
    for (int i = 0; i < 2; i++) {
        x *= 10;
        x += n%10;
        n /= 10;
    }
    printf("%d\n", x) ;
    if (x == 86 || x == 68) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}