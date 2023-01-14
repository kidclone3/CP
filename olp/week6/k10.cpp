#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll l, v1, v2;
    scanf("%lld%lld%lld", &l, &v1, &v2);
    int q;
    scanf("%d", &q);
    while(q--) {
        ll s;
        scanf("%lld", &s);
        double t = 2.0/sqrt(2.0) *(l-sqrt(s)) / abs(v1-v2);
        printf("%.20f\n", t);
    }
}