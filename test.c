#include<stdio.h>
#include<stdbool.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
int main() {
    int n = 6;
    int a[] = {11, 11, 14, 14, 3, 15};

    int c[100];
    int z = 0;
    FOR(i, n) {
        bool notfound = true;
        FOR(j, i) {
            if (a[i] == a[j]) {
                notfound = false;
                break;
            }
        }
        if (notfound) {
            c[z] = a[i];
            z++;
        }
    }
    FOR(i, z) {
        printf("%d ", c[i]);
    }
}