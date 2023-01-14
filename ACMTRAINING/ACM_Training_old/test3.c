#include<stdio.h>
void inc(int &a) {
    a++;
}
int main() {
    int a = 5;
    inc(a);
    printf("%d ", a);
}