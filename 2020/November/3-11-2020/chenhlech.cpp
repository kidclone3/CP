#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(int n, ll a[], int au, int av);

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, q;
   cin >> n >> q;
   ll a[n];
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      if (i != 0)
         a[i] += a[i - 1];
   }
   for (int i = 0; i < q; i++)
   {
      int b1, b2;
      cin >> b1 >> b2;
      cout << solve(n, a, b1, b2) << '\n';
   }
}

ll solve(int n, ll a[], int u, int v)
{
   ll res = LONG_LONG_MAX;
   ll last = a[v - 1];
   ll head;
   if (u == 1)
      head = 0;
   else
      head = a[u - 2];
   register int i;
   for (int i=u-1; i<v; i++){
   	res=min(res,abs(last-a[i]-(a[i]-head)));
	}
   
   return res;
}
