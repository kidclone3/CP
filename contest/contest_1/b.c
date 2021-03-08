#include <stdio.h>
int main() {
    char a[10000000+5];
    scanf("%s", &a);
    int l=0;
    while (a[l] !='\0') l++;
    int i=0, j=l;
    while(a[i]!='A') i++;
    while(a[j]!='Z') j--;
    print("%d", j-i+1);

}