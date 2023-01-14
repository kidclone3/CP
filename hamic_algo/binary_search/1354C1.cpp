#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        double n; 
        scanf("%lf", &n);
        n *= 2.0;
        double pi = 2*acos(0);
        double h = 2 * sqrt(1.0/(4*sin(pi/n)*sin(pi/n)) - 1.0/4.0);
        printf("%.8lf\n", h);
    }
}