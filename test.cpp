#include <stdio.h>
int main(){
    int t ;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;float sum=0;
        scanf("%d", &n);
        if (n % 2 == 0){
            for (float j=2.0; j<n;j= j+2.0)
                sum = sum + 1.0/j;
        }
        else {
            for (int j=1.0; j<n;j= j+2.0)
                sum = sum + 1.0/j;
        }
            printf("%f\n", sum);
    }
    return 0;
}