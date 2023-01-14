#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
//#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
int n, i, t, b, k, j;
char a[10];
int main() {
  // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  scanf("%d", &n);
  for (i = 1; i <= 10; i++) {
    for (j = 1; j <= n; j++)
      if ((j & (1 << (i - 1))) == 0)
        printf("%d ", j);
    printf("\n");
  }
  b = 0;
  for (i = 1; i <= 10; i++) {
    scanf("%8s", &a);
    if (a[0] == 'N')
      b = (b ^ (1 << (i - 1)));
  }
  if (b > n || b == 0)
    printf("-1");
  else
    printf("%d", b);
}
