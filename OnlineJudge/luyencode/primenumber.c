#include <stdio.h>
#include <stdbool.h>
bool isPrime(int n) {
    if (n<2) return false;
    if (n==2) return true;
    if (!(n%2)) return false;
    for (int i = 2; i*i<=n; ++i) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    scanf("%d", &n);
    int storage[110];
    int j = 0;
    while(n--) {
        int x;
        scanf("%d", &x);
        if (isPrime(x)) storage[j++] = x;
    }
    printf("%d ", j);
    for (int i = 0; i<j; ++i) {
        printf("%d ", storage[i]);
    }
    return 0;
}