#include <cstdio>
#include <algorithm>
 
const int MN = 2e5+10;
 
int N, M, a[MN], p[MN], ans;
bool ok[MN];
 
void check(int x)
{
	if(x<1 || x>=N) return;
	if(ok[x]!=(p[x]>p[x+1])) // = if (p[x] > p[x+1]) ==> round++;
		ans += (ok[x]^=1)*2-1;  // array OK => Save relation of x and x+1. 
								// (0 is in one round, 1 is in another)
}
 
int main()
{
	scanf("%d%d", &N, &M);
 
	for(int i=1;i<=N;++i)
		scanf("%d", a+i), p[a[i]]=i;
	ans=1;
	for(int i=1;i<N;++i)
		check(i);
 
	for(int i=0,u,v;i<M;++i)
	{
		scanf("%d%d", &u, &v);
		std::swap(a[u], a[v]);
		std::swap(p[a[u]], p[a[v]]);
		check(a[u]-1);
		check(a[u]);
		check(a[v]-1);
		check(a[v]);
		printf("%d\n", ans);
	}
 
	return 0;
}