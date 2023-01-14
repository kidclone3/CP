#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100005
int m, n, a[N], l[N], Root[N], Peak=0;
int Sum[80*N], Left[80*N], Right[80*N]; // (n*4)+(n log n)

int create(int n){
    if (n==1) { ++Peak; Sum[Peak]=0; return Peak; }
    int u = ++Peak;
    Left[u]=create(n-n/2);
    Right[u]=create(n/2);
    return u;
}

struct node {
    int ll, rr, id;

    node(int L, int R, int X)
    { ll=L, rr=R, id=X; }
    node left()
    { return node(ll, (ll+rr)/2, Left[id]); }
    node right()
    { return node((ll+rr)/2+1, rr, Right[id]); }

    int update(int U, int X){
        if (ll>U || U>rr) return id;
        if (ll==rr) { Sum[++Peak]=X; return Peak; }
        int u = ++Peak;
        Left[u] = left().update(U, X);
        Right[u] = right().update(U, X);
        Sum[u]=Sum[Left[u]]+Sum[Right[u]];
        return u;
    }
    int sum_range(int L, int R){
        if (L>rr || ll>R || L>R) return 0;
        if (L<=ll && rr<=R) return Sum[id];
        int Sum1 = left().sum_range(L, R);
        int Sum2 = right().sum_range(L, R);
        return Sum1 + Sum2;
    }
};

bool as_a(int x, int y)
    { return a[x]<a[y]; }

main(){
    scanf("%d%d", &n, &m);
    f1(i,n) scanf("%d", &a[i]);
//    f1(i,n) printf("%d ", a[i]=rand()%100); printf("\n");

    f1(i,n) l[i]=i;
    sort(l+1, l+n+1, as_a);
    Root[0]=create(n);
    f1(i,n) {
        Root[i]=node(1, n, Root[i-1]).update(l[i], 1);
//        cout << endl << Peak << " " << 80*N << endl;
    }

    f1(i,m) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        int ll=1, rr=n, mm=(ll+rr)/2;
        while (ll!=rr){
            if (node(1, n, Root[mm]).sum_range(x, y)>=z) rr=mm; else ll=mm+1;
            mm=(ll+rr)/2;
        }
        printf("%d\n", a[l[mm]]);
    }
}