#include <stdio.h>
#include <stdlib.h>
int main() {
    srand(333);
    for(int i = 0; i < 30; ++i) {
        printf("%f\n", (double) rand()/RAND_MAX);
    }
}
