#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod (ll) 1200000090
#define N 40000005
int  lp[N+1];
vector<int > pr;
void solve(){
for (int  i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int  j=0; j<(ll )pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}
}
 
ll  po(ll  a,ll  n){
  ll  res=a, ans=1;
  while(n){
    if(n%2) ans=ans*res%mod;
    res=res*res%mod;
    n/=2;
  }
  return ans;
}
ll  aka(ll  p, ll  alpha){
  if(alpha==0) return 1;
  if(alpha==1) return (p+1)%mod;
  if(alpha%2==1) return (p*aka(p,alpha-1)%mod+1)%mod;
  if(alpha%2==0) return ((po(p,alpha/2)+1)*((aka(p,alpha/2)-1+mod)%mod)%mod+1)%mod;
}
ll  f(ll  n){
  ll  tmp,i=0,so_mu,res=1;
  while(pr[i]<=n){
    tmp=pr[i];
    so_mu=0;
    while(tmp<=n){
        so_mu = so_mu+ (n/tmp);
        tmp=tmp*pr[i];
    }
    res=res*aka(pr[i],so_mu*3)%mod;
    //res=res*(so_mu+1)*(so_mu+2)/2%mod;
    i++;
  }
  return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll  n,res,testcase;
    solve();
    cin>>testcase;
   while(testcase--){
      cin>>n;
      if(n==0) break;
      res=f(n);
      cout<<res<<'\n';
   }
}
